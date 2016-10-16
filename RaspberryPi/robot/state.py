from robot.leg import Leg


class State:

    def __init__(self):
        self.leg_1 = Leg()
        self.leg_2 = Leg()
        self.leg_3 = Leg()
        self.leg_4 = Leg()
        self.leg_5 = Leg()
        self.leg_6 = Leg()

        self.leg_1.set_angles(90, 100, 120)
        self.leg_2.set_angles(90, 100, 120)
        self.leg_3.set_angles(90, 100, 120)
        self.leg_4.set_angles(90, 100, 120)
        self.leg_5.set_angles(90, 100, 120)
        self.leg_6.set_angles(90, 100, 120)

    def home(self):
        #home_packet = Packet()

        self.leg_1.set_angles(90, 100, 120)
        self.leg_2.set_angles(90, 100, 120)
        self.leg_3.set_angles(90, 100, 120)
        self.leg_4.set_angles(90, 100, 120)
        self.leg_5.set_angles(90, 100, 120)
        self.leg_6.set_angles(90, 100, 120)

        #home_packet.set_leg(1, self.leg_1)
        #home_packet.set_leg(2, self.leg_2)
        #home_packet.set_leg(3, self.leg_3)
        #home_packet.set_leg(4, self.leg_4)
        #home_packet.set_leg(5, self.leg_5)
        #home_packet.set_leg(6, self.leg_6)

        #home_packet.make_packet()
        #packet_list = [home_packet]
        #return packet_list

    def storage(self):
        storage_packet = Packet()

        self.leg_1.set_angles(60, 15, 20)
        self.leg_2.set_angles(60, 15, 20)
        self.leg_3.set_angles(60, 15, 20)
        self.leg_4.set_angles(60, 15, 20)
        self.leg_5.set_angles(60, 15, 20)
        self.leg_6.set_angles(60, 15, 20)

        storage_packet.set_leg(1, self.leg_1)
        storage_packet.set_leg(2, self.leg_2)
        storage_packet.set_leg(3, self.leg_3)
        storage_packet.set_leg(4, self.leg_4)
        storage_packet.set_leg(5, self.leg_5)
        storage_packet.set_leg(6, self.leg_6)

        storage_packet.make_packet()
        packet_list = [storage_packet]
        return packet_list

    def forward(self):
        packet_list = []

        #pos 1 - centered
        forward_packet_1 = Packet()

        self.leg_1.set_angles(90, 110, 60)
        self.leg_2.set_angles(90, 70, 20)
        self.leg_3.set_angles(100, 70, 20)
        self.leg_4.set_angles(90, 110, 60)
        self.leg_5.set_angles(90, 110, 40)
        self.leg_6.set_angles(100, 70, 20)

        forward_packet_1.set_leg(1, self.leg_1)
        forward_packet_1.set_leg(2, self.leg_2)
        forward_packet_1.set_leg(3, self.leg_3)
        forward_packet_1.set_leg(4, self.leg_4)
        forward_packet_1.set_leg(5, self.leg_5)
        forward_packet_1.set_leg(6, self.leg_6)

        forward_packet_1.make_packet()
        packet_list.append(forward_packet_1)

        #pos 2 - front (right side legs)
        forward_packet_2 = Packet()

        self.leg_1.set_angles(120, 110, 40)
        self.leg_2.set_angles(100, 70, 20)
        self.leg_3.set_angles(110, 70, 20)
        self.leg_4.set_angles(120, 110, 40)
        self.leg_5.set_angles(110, 110, 55)
        self.leg_6.set_angles(110, 70, 20)

        forward_packet_2.set_leg(1, self.leg_1)
        forward_packet_2.set_leg(2, self.leg_2)
        forward_packet_2.set_leg(3, self.leg_3)
        forward_packet_2.set_leg(4, self.leg_4)
        forward_packet_2.set_leg(5, self.leg_5)
        forward_packet_2.set_leg(6, self.leg_6)

        forward_packet_2.make_packet()
        packet_list.append(forward_packet_2)

        #pos 3 - up front
        forward_packet_3 = Packet()

        self.leg_1.set_angles(110, 70, 20)
        self.leg_2.set_angles(110, 110, 55)
        self.leg_3.set_angles(120, 110, 40)
        self.leg_4.set_angles(110, 70, 20)
        self.leg_5.set_angles(100, 70, 20)
        self.leg_6.set_angles(120, 110, 40)

        forward_packet_3.set_leg(1, self.leg_1)
        forward_packet_3.set_leg(2, self.leg_2)
        forward_packet_3.set_leg(3, self.leg_3)
        forward_packet_3.set_leg(4, self.leg_4)
        forward_packet_3.set_leg(5, self.leg_5)
        forward_packet_3.set_leg(6, self.leg_6)

        forward_packet_3.make_packet()
        packet_list.append(forward_packet_3)

        #pos 4 - up centered
        forward_packet_4 = Packet()

        self.leg_1.set_angles(100, 70, 20)
        self.leg_2.set_angles(90, 110, 40)
        self.leg_3.set_angles(90, 110, 60)
        self.leg_4.set_angles(100, 70, 20)
        self.leg_5.set_angles(90, 70, 20)
        self.leg_6.set_angles(90, 110, 60)

        forward_packet_4.set_leg(1, self.leg_1)
        forward_packet_4.set_leg(2, self.leg_2)
        forward_packet_4.set_leg(3, self.leg_3)
        forward_packet_4.set_leg(4, self.leg_4)
        forward_packet_4.set_leg(5, self.leg_5)
        forward_packet_4.set_leg(6, self.leg_6)

        forward_packet_4.make_packet()
        packet_list.append(forward_packet_4)

        #pos 5 - up back
        forward_packet_5 = Packet()

        self.leg_1.set_angles(90, 70, 20)
        self.leg_2.set_angles(60, 110, 55)
        self.leg_3.set_angles(80, 110, 90)
        self.leg_4.set_angles(90, 70, 20)
        self.leg_5.set_angles(70, 70, 20)
        self.leg_6.set_angles(80, 110, 90)

        forward_packet_5.set_leg(1, self.leg_1)
        forward_packet_5.set_leg(2, self.leg_2)
        forward_packet_5.set_leg(3, self.leg_3)
        forward_packet_5.set_leg(4, self.leg_4)
        forward_packet_5.set_leg(5, self.leg_5)
        forward_packet_5.set_leg(6, self.leg_6)

        forward_packet_5.make_packet()
        packet_list.append(forward_packet_5)

        #pos 6 - back
        forward_packet_6 = Packet()

        self.leg_1.set_angles(80, 110, 90)
        self.leg_2.set_angles(70, 70, 20)
        self.leg_3.set_angles(90, 70, 20)
        self.leg_4.set_angles(80, 110, 90)
        self.leg_5.set_angles(60, 110, 55)
        self.leg_6.set_angles(90, 70, 20)

        forward_packet_6.set_leg(1, self.leg_1)
        forward_packet_6.set_leg(2, self.leg_2)
        forward_packet_6.set_leg(3, self.leg_3)
        forward_packet_6.set_leg(4, self.leg_4)
        forward_packet_6.set_leg(5, self.leg_5)
        forward_packet_6.set_leg(6, self.leg_6)

        forward_packet_6.make_packet()
        packet_list.append(forward_packet_6)

        return packet_list

    def user_state(self, leg, shoulder, elbow, foot):
        user_packet = Packet()
        if leg == 1:
            self.leg_1.set_angles(shoulder, elbow, foot)
        elif leg == 2:
            self.leg_2.set_angles(shoulder, elbow, foot)
        elif leg == 3:
            self.leg_3.set_angles(shoulder, elbow, foot)
        elif leg == 4:
            self.leg_4.set_angles(shoulder, elbow, foot)
        elif leg == 5:
            self.leg_5.set_angles(shoulder, elbow, foot)
        elif leg == 6:
            self.leg_6.set_angles(shoulder, elbow, foot)

        user_packet.set_leg(1, self.leg_1)
        user_packet.set_leg(2, self.leg_2)
        user_packet.set_leg(3, self.leg_3)
        user_packet.set_leg(4, self.leg_4)
        user_packet.set_leg(5, self.leg_5)
        user_packet.set_leg(6, self.leg_6)

        user_packet.make_packet()
        packet_list = [user_packet]
        return packet_list
