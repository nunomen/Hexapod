import packet
from serial import Serial, SerialException
from robot.leg import Leg


sample_packet = packet.Packet()

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

# Verify that the packet is well built, for debugging purposes.
for character in sample_packet.get_pack():
    print(character, ord(character))


if __name__ == "__main__":
    # TODO Make a rule on raspberry pi for Arduino, so that the port always stays the same.
    port = '/dev/ttyACM0'
    # Configure the baud rate of the connection.
    baud_rate = 9600

    try:
        serial = Serial(port, baud_rate)

        for x in sample_packet.get_pack():
            serial.write(x)

    except SerialException:
        print("Connection Failure.")