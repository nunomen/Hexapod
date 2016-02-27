

# Class leg will be moved to the kinematics package
class Leg:

    def __init__(self):
        self.data = []

    def set_angles(self, coxa, femur, tibia):
        self.data = [coxa, femur, tibia]

    def angles(self):
        return self.data