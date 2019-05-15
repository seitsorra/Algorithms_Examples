import unittest
import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import numWaysToMakeChange as program


class NumWayUnitTest(unittest.TestCase):
    def test_case_1(self):
        self.assertEqual(program.numWaysToMakeChange(0, [2,3,4,7]) , 1)
    def test_case_2(self):
        self.assertEqual(program.numWaysToMakeChange(9, [5]) , 0)
    def test_case_3(self):
        self.assertEqual(program.numWaysToMakeChange(7, [2,4]) , 0)
    def test_case_4(self):
        self.assertEqual(program.numWaysToMakeChange(6, [1,5]) , 2)
    def test_case_5(self):
        self.assertEqual(program.numWaysToMakeChange(4, [1,5,10,25]) , 1)
    def test_case_6(self):
        self.assertEqual(program.numWaysToMakeChange(5, [1,5,10,25]) , 2)
    def test_case_7(self):
        self.assertEqual(program.numWaysToMakeChange(10, [1,5,10,25]) , 4)
    def test_case_8(self):
        self.assertEqual(program.numWaysToMakeChange(25, [1,5,10,25]) , 13)
    def test_case_9(self):
        self.assertEqual(program.numWaysToMakeChange(12, [2,3,7]) , 4)
    def test_case_10(self):
        self.assertEqual(program.numWaysToMakeChange(7, [2,3,4,7]) , 3)


if __name__ == "__main__":
    unittest.main()
    
