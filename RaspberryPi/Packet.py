class Packet:
    def __init__(self):
        self.data = ""
        self.legs = {}

    def set_leg(self, number, leg):
        # Associate a leg object with its identifier.
        self.legs.update({number: leg})

    def leg(self, number):
        # Get the leg object with 'number' key.
        return self.legs[number]

    def make_packet(self):
        # Produces the packet from the given leg angles.
        flg = list('00000000')
        for i in self.legs.keys():
            flg[8-i] = '1'
        pack = chr(222) + chr(230) + chr(222) + chr(int(''.join(flg), 2))
        for leg in self.legs.keys():
            vec = self.legs[leg].angles()
            for angle in vec:
                pack += chr(angle)
        pack += chr(233)
        self.data = pack

    def __repr__(self):
        # Returns the string representation for the packet object.
        return self.data