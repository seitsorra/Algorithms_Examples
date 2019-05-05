'''
    THREE NUMBER SUM

    Write a function that takes in a non-empy array of distinct integres and an integer
    representing a target sum. The function should find all triplets in the array that sum up
    to the target sum and return a two-dimensional array of all these triplets. The numbers in each
    triplet should be ordered in ascending order, and the triplets themselves should be ordered in
    ascending order with the respect to the numbers they hold. If no three numbers sum up to the target
    sum, the function should return an empty array.

    SAMPLE INPUT:
        - [12,3,1,2,-6,5,-8,6], 0
    
    SAMPLE OUTPUT
        -[[-8,2,6], [-8,3,5], [-6,1,5]]
'''


def threeNumberSum(array, targetSum):

	"""Gets an array of integers and a target sum and find a list of tuples that add to sum in the list

	Paremeters:
		array: an array of integers
		targetSum: int representing the target sum
	Returns:
		list: a list of tuples in ascending order whose values add up to target sum

	"""

	array.sort()
	staticIdx = 0
	ret = []
	while(staticIdx != len(array) -2):
		left = staticIdx+1
		right = len(array)-1
		for idx in range(left, len(array)-1):
			if(left >= right): 
				break
			
			sumVal = array[staticIdx] + array[left] + array[right]
			
			if sumVal == targetSum:
				triple = [array[staticIdx], array[left], array[right] ]
				ret.append(triple)
				left+=1
				right-=1
			elif sumVal < targetSum:
				left+=1
			else:
				right-=1
		
		staticIdx+=1
	return ret


if __name__ == "__main__":
    v = [12,3,1,2,-6,5,-8,6]
    num = 0

    if(threeNumberSum(v, num) != [[-8,2,6], [-8,3,5], [-6,1,5]]):
        print("Failed")
    else:
        print("Passed")