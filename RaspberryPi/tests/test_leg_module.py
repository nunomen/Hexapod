import unittest
import sys


try:
    sys.path.append('../robot')
    import leg

except ImportError:
    print('Could not find leg file!')

class TestLegMethods(unittest.TestCase):

    def setUp(self):
        self.leg = leg.Leg()

    def test_angles(self):
        angles = {'shoulder': 90, 'elbow': 100, 'wrist': 120}
        self.leg.set_angles(angles)
        self.assertEqual(self.leg.angles(), angles)

if __name__ == '__main__':
    unittest.main()
