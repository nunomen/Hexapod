from packet import Packet
from serial import Serial, SerialException
from robot.leg import Leg
from sys import argv


def main(args):
    sample_packet = Packet()

    leg_1 = Leg()
    leg_2 = Leg()
    leg_3 = Leg()
    leg_4 = Leg()
    leg_5 = Leg()

    leg_1.set_angles(30, 20, 20)
    leg_2.set_angles(45, 60, 130)
    leg_3.set_angles(30, 43, 31)
    leg_4.set_angles(19, 41, 42)
    leg_5.set_angles(32, 20, 90)

    sample_packet.set_leg(1, leg_1)
    sample_packet.set_leg(2, leg_2)
    sample_packet.set_leg(3, leg_3)
    sample_packet.set_leg(4, leg_4)
    sample_packet.set_leg(5, leg_5)

    sample_packet.make_packet()

    # TODO Make a rule on raspberry pi for Arduino, so that the port always stays the same.
    port = '/dev/ttyACM0'
    # Configure the baud rate of the connection.
    baud_rate = 9600

    for i in range(len(args)):
        mode = args[i]
        if mode == '-d':
            print('[LOG]: This program is in debug mode.')
        elif mode == '-br':
            print('[LOG]: The baud rate is set to %s', args[i+1])
            baud_rate = args[i+1]
        elif mode == '-p':
            print('[LOG]: The Arduino port was set to %s', args[i+1])
            port = args[i+1]

    # Verify that the packet is well built, for debugging purposes.
    for character in str(sample_packet):
        print(character, ord(character))

    try:
        serial = Serial(port, baud_rate)

        for x in str(sample_packet):
            serial.write(x)

    except SerialException:
        print("[ERROR]: Connection Failure.")

if __name__ == "__main__":
    main(argv)
