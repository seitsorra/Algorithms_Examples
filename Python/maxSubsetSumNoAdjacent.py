'''
Maximum Subset Sum With No Adjacent Elements

Write a function that takes in an array of positives integers and returns
an integer representing the maximum sum of non-adjacent elements in the array.
If a sum cannot be generated, the function should return 0.

Sample input:  [75, 105, 120, 75, 90, 135]
Sample output: 330 - [75, 120, 135]


SOLUTION EXPLAINED:
    Here we will make use of dynamic programming and build another array with maximum sum as we traverse the provided one

    So for array:        [75, 105, 120, 75, 90, 135]
    Use    maxSumArray:  [75, 105, 0 , 0 , 0 , 0]

    Since we cannot use the adjacent values then for each index in the provided array we can use the following formula to determine
    max sum:

        sum = max(maxSumArray[idx-1], (maxSumArray[idx-2]+array[idx]))
    
    Also to make things easier we can do the following:
        - if array has size less than 2 then no sum can be generated so return 0
        - populate the first two index of dynamic max sum with respective indexs of the provided array and start iterating at (idx=2)

'''

# O(n) time & O(n) space
def maxSubsetSumNoAdjacent(arr):
    if len(arr) == 2 or len(arr) == 0:
        return 0
    elif len(arr) == 1:
        return arr[0]

    maxSum = [n for n in arr]

    idx = 2
    while idx < len(arr):
        maxSum[idx] = max(maxSum[idx-1], (maxSum[idx-2] + arr[idx]))
        idx += 1

    return maxSum[len(arr)-1]

# O(n) time & O(1) space
def maxSubsetSumNoAdjacentConstSpace(arr):
    if len(arr) == 2 or len(arr) == 0:
        return 0
    elif len(arr) == 1:
        return arr[0]

    prevLast = arr[0]
    last = arr[1]
    for idx in range(2, len(arr)):
        current = max(last, prevLast+arr[idx])
        prevLast = last
        last = current

    return last

if __name__ == "__main__":
    v = [75, 105, 120, 75, 90, 135]
    print("PASSED" if maxSubsetSumNoAdjacentConstSpace(v) == 330 else "FAILED")