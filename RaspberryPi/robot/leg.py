

class Leg(object):

    def __init__(self):
        self._leg = {'shoulder': None, 'elbow': None, 'wrist': None}

    def set_angles(self, angles):
        self._leg.update(angles)

    def angles(self):
        return self._leg

    def __repr__(self):
        r = ''
        for joint_name in self._leg:
            r += joint_name + ': ' + str(self._leg.get(joint_name)) + '\n'
        return r

if __name__ == "__main__":
    pass
