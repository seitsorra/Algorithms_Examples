'''
Number of Ways To Make Change

Given an array of positive integers representing coin denominations and a single
non-negative integer representing a target amount of money, implement a 
function that returns the number of ways to make change for that target
amount using the given coin denominations.
Note that an unlimited amount of coins is at your disposal.

Sample input: 6, [1,5]
Sample output: 2 (1x1 + 1x5 and 6x1)
'''

def numWaysToMakeChange(target, denoms):
    numWays = [0 for amount in range(target+1)]
    numWays[0] = 1

    for denom in denoms:
        for amount in range(1, target+1): # Skip the first index since it will never satisfy the if following if statement
            if denom <= amount:
                numWays[amount] = numWays[amount] + numWays[amount-denom]
    
    return numWays[target]