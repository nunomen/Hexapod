class Packet:
    def __init__(self):
        self.data = {}

    # Associate a leg with angles to be moved in the next step
    def set_leg(self, number, leg):
        self.data.update({number: leg})

    # Get Leg id that will be moved
    def leg(self, number):
        return self.data[number]

    # Return the string to be sent to arduino
    def get_pack(self):
        flg = list('00000000')
        for i in self.data.keys():
            flg[8-i] = '1'
        pack = chr(222) + chr(230) + chr(222) + chr(int(''.join(flg), 2))
        for leg in self.data.keys():
            vec = self.data[leg].angles()
            for angle in vec:
                pack += chr(angle)
        return pack


# Class leg will be moved to the kinematics package
class Leg:

    def __init__(self):
        self.data = []

    def set_angles(self, coxa, femur, tibia):
        self.data.extend([coxa, femur, tibia])

    def angles(self):
        return self.data
