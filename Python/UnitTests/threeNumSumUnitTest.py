import unittest
import threeNumSum as program

class ThreeNumSumUnitTest(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(program.threeNumberSum([1,2,3], 6), [[1,2,3]])

    def test_case2(self):
        self.assertEqual(program.threeNumberSum([1,2,3], 7), [])
    
    def test_case3(self):
        self.assertEqual(program.threeNumberSum([8,10,-2,49,14], 57), [[-2,10,49]])
    
    def test_case4(self):
        self.assertEqual(program.threeNumberSum([12,3,1,2,-6,5,-8,6], 0), [[-8,2,6], [-8,3,5], [-6,1,5]])
    
    def test_case5(self):
        self.assertEqual(program.threeNumberSum([12,3,1,2,-6,5,0,-8,-1], 0), [[-8,3,5], [-6,1,5], [-1,0,1]])
    
    def test_case6(self):
        self.assertEqual(program.threeNumberSum([12,3,1,2,-6,5,0,-8,-1,6], 0), [[-8,2,6], [-8,3,5], [-6,0,6], [-6,1,5], [-1,0,1]])
    
    def test_case7(self):
        self.assertEqual(program.threeNumberSum([12,3,1,2,-6,5,0,-8,-1,6,-5], 0), [[-8,2,6],[-8,3,5],[-6,0,6],[-6,1,5],[-5,-1,6],[-5,0,5],[-5,2,3],[-1,0,1]])
    
    def test_case8(self):
        self.assertEqual(program.threeNumberSum([1,2,3,4,5,6,7,8,9,15], 18), [[1,2,15], [1,8,9], [2,7,9], [3,6,9], [3,7,8], [4,5,9], [4,6,8], [5,6,7]])
    
    def test_case9(self):
        self.assertEqual(program.threeNumberSum([1,2,3,4,5,6,7,8,9,15], 32), [[8,9,15]])
    
    def test_case10(self):
        self.assertEqual(program.threeNumberSum([1,2,3,4,5,6,7,8,9,15], 33), [])

    def test_case11(self):
        self.assertEqual(program.threeNumberSum([1,2,3,4,5,6,7,8,9,15], 5), [])

if __name__ == "__main__":
    unittest.main()