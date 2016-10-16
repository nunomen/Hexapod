from leg import Leg


class State(object):


    def __init__(self):
        self._legs = {1:Leg(), 2:Leg(), 3:Leg(),
                     4:Leg(), 5:Leg(), 6:Leg()}
        self.set_home()

    def legs(self):
        return self._legs

    def set_home(self):
        # Set the robot to home configuration
        angles = {'shoulder': 90, 'elbow': 100, 'wrist': 120}
        for i in self._legs:
            self._legs.get(i).set_angles(angles)

    def set_storage(self):
        # Set the robot to storage configuration
        angles = {'shoulder': 60, 'elbow': 15, 'wrist': 20}
        for i in self._legs:
            self._legs.get(i).set_angles(angles)

    def set_joint_states(self, joint_states):
        # Set a custom joint configuration
        for i in self._legs:
            angles = joint_states.get(i)
            self._legs.get(i).set_angles(angles)

    def __repr__(self):
        r = ''
        for leg_name in self._legs:
            r += leg_name + ': ' + str(self._legs.get(leg_name)) + '\n'
        return r

if __name__ == '__main__':
    pass
