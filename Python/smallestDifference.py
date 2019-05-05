'''
    SMALLEST DIFFERENCE

    Write a function that takes in two non-empty arrays of integers. The function should find the pair of numbers (One from the first array,
    one from the second array), whose absolute difference is closest to zero. The function should return an array containing these two
    numbers, with the number from the first array in the first position. Assume there will be only one pair of numbers with the smallest difference.

    Sample Input:
        [-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]
    Output:
        [28, 26]
'''

def smallestDifference(arrayOne, arrayTwo):
    """
    Gets two arrays of integers and finds a pair with absolute difference closest to 0

    Parameters:
        arrayOne: first array of integers
        arrayTwo: second array of integers

    Returns:
        smallest pair (first num from first array and second num from second array)

    """

    arrayOne.sort()
    arrayTwo.sort()

    idxOne = 0
    idxTwo = 0
    smallest = float("inf")
    current = float("inf")
    smallestPair = []

    while idxOne < len(arrayOne) and idxTwo < len(arrayTwo):
        first = arrayOne[idxOne]
        second = arrayTwo[idxTwo]

        if first < second:
            current = second-first
            idxOne += 1
        elif second < first:
            current = first - second
            idxTwo += 1
        else:
            return [first, second]
        
        if smallest > current:
            smallest = current
            smallestPair = [first, second]
    
    return smallestPair

if __name__ == "__main__":
    pass
