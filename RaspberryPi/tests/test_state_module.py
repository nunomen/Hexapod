import unittest
import sys
import random


try:
    sys.path.append('../robot')
    import state

except ImportError:
    print('Could not find state file!')


class TestLegMethods(unittest.TestCase):

    def setUp(self):
        self.st = state.State()

    def test_home_configuration(self):
        angles = {'shoulder': 90, 'elbow': 100, 'wrist': 120}
        self.st.set_home()
        for i in self.st.legs():
            self.assertEqual(self.st.legs().get(i).angles(), angles)

    def test_storage_configuration(self):
        angles = {'shoulder': 60, 'elbow': 15, 'wrist': 20}
        self.st.set_storage()
        for i in self.st.legs():
            self.assertEqual(self.st.legs().get(i).angles(), angles)

    def test_custom_configuration(self):
        test_case_angles = {}
        for i in self.st.legs():
            angles = {'shoulder': random.random(), 'elbow': random.random(),
                        'wrist': random.random()}
            test_case_angles[i] = angles
        self.st.set_joint_states(test_case_angles)
        for i in self.st.legs():
            self.assertEqual(self.st.legs().get(i).angles(),
                                test_case_angles.get(i))


if __name__ == '__main__':
    unittest.main()
