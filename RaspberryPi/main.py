from Packet import Packet
from robot.leg import Leg
from robot.state import State
from serial.tools import list_ports
from serial import Serial, SerialException
from sys import argv
from time import sleep, time


def main(args):

    current_state = State()

    # Configure the baud rate of the connection.
    baud_rate = 9600
    debug = False
    packet_nr = 0
    packet_period = 0.3
    last_packet_timestamp = 0

    for i in range(len(args)):
        mode = args[i]
        if mode == '-d':
            print('[LOG]: This program is in debug mode.')
            debug = True
        elif mode == '-br':
            print('[LOG]: The baud rate is set to ' + args[i+1])
            baud_rate = args[i+1]
        elif mode == '-p':
            print('[LOG]: The Arduino port was set to ' + args[i+1])
            # port = args[i+1]

    for port in (list_ports.comports()):
        print(port[0])
        try:
            ser = Serial(port[0], baud_rate, timeout=2)
            sleep(3)  # wait for the device to be ready

            packet_list = current_state.home()
            send_packet(packet_list[0], ser)

            incoming_byte = ser.read()

            # discard initial bytes
            while incoming_byte:
                incoming_byte = ser.read()

            while True:
                command = input(">> ")
                words = command.split()

                if len(words) > 0 and words[0] == 'debug':
                    debug = True
                    print("[LOG]: Debug mode activated.")

                elif len(words) > 0 and words[0] == 'ddebug':
                    debug = False
                    print("[LOG]: Debug mode deactivated.")

                elif len(words) == 5 and words[0] == 'leg':
                    packet_list = current_state.user_state(int(words[1]), int(words[2]), int(words[3]), int(words[4]))
                    send_packet(packet_list[0], ser)

                elif len(words) > 0 and words[0] == 'storage':
                    print("[LOG]: Hexapod is preparing himself to be packed.")
                    packet_list = current_state.storage()
                    send_packet(packet_list[0], ser)

                elif len(words) > 0 and words[0] == 'home':
                    print("[LOG]: Default leg position.")
                    packet_list = current_state.home()
                    send_packet(packet_list[0], ser)

                elif len(words) > 0 and words[0] == 'off':
                    print("[LOG]: Hexapod is shuting down.")
                    ser.close()
                    return

                elif len(words) > 0 and words[0] == 'forward':
                    print("[LOG]: Hexapod is walking forward.")
                    packet_list = current_state.forward()
                    while True:
                        if time() - last_packet_timestamp >= packet_period:
                            real_packet = packet_nr % len(packet_list)
                            send_packet(packet_list[real_packet], ser)
                            last_packet_timestamp = time()
                            packet_nr += 1

                start_time = int(round(time()))
                if debug is True:
                    incoming_byte = ser.read()
                    while int(round(time())) - start_time < 1 and incoming_byte:
                        if incoming_byte:
                            if ord(incoming_byte) == 253:
                                print('[LOG]: Received valid packet.')
                            elif ord(incoming_byte) == 251:
                                print('[LOG]: Detected terminal character.')
                            elif ord(incoming_byte) == 252:
                                print('[WARNING]: Exceeded possible packet size.')
                            elif 200 <= ord(incoming_byte) <= 218:
                                print('[LOG]: Byte ' + str(ord(incoming_byte) - 200) + ':')
                            elif ord(incoming_byte) == 222:
                                print('[LOG]: First or third initiation character found.')
                            elif ord(incoming_byte) == 230:
                                print('[LOG]: Second initiation character found.')
                            elif 190 <= ord(incoming_byte) <= 195:
                                print('[LOG]: Simulating Leg ' + str(ord(incoming_byte) - 190) + ' actuation.')
                            elif ord(incoming_byte) == 233:
                                print('[LOG]: Termination byte found.')
                            elif ord(incoming_byte) == 249:
                                print('[WARNING]: Servo amplitude range exceeded. Setting it to the established limit.')
                            else:
                                print(ord(incoming_byte))
                        incoming_byte = ser.read()

        except SerialException:
            # print("opening serial failed")
            print("[ERROR]: Connection Failure.")
            pass


def send_packet(packet, serial):
    for character in str(packet):
        serial.write(bytes([ord(character)]))

if __name__ == "__main__":
    main(argv)
