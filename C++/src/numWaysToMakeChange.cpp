/*
Number of Ways To Make Change

Given an array of positive integers representing coin denominations and a single
non-negative integer representing a target amount of money, implement a 
function that returns the number of ways to make change for that target
amount using the given coin denominations.
Note that an unlimited amount of coins is at your disposal.

Sample input: 6, [1,5]
Sample output: 2 (1x1 + 1x5 and 6x1)
*/

#include "utils.h"

/* 
    We are going to make use of dynamic programming to solve this issue.

    The solution consists of creating an array of size target with all the dollar values until our target.

    i.e. when target is 10$ the array that we will build will be
        - [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]    <--- array values
           |  |  |  |  |  |  |  |  |  |  |
           0  1  2  3  4  5  6  7  8  9  10     <--- array indexes

    We will build this array by iterating through each denominator and determining for each index in the array what
    is the minimum number of changes that will sum to the array idx value (Dollar value)

    For that we will use the following formula:

        if(denom <= amount)
            ways[amount] += ways[amount - denom]
    
    NOTE: Initially we will initialize the array of ways to be all zero values except from first index be 1.
          Becuase there is really one single way to form 0 dollar amount (just give nothing)
*/
int numberOfWaysToMakeChange(int target, vector<int> denoms){
    vector<int> numWays(target+1, 0);
    numWays[0] = 1;

    for(int denom : denoms){
        for(int amount = 1; amount < numWays.size(); amount++){
            // So basically if our denominator (coin change) is less than dollar amount we know for sure
            // that we can fit this coin change to create the dollar amount
            // therefore we can update the number of ways at this dollar amount + number of ways for difference of dollar amount and coin change(denominator)
            if(denom <= amount){
                numWays[amount] = numWays[amount] + numWays[amount - denom];
            }
        }
    }

    return numWays[target];
}

struct TestCase{
    vector<int> denominations;
    int targetChange;
    int expNumWays;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.denominations = {2,3,4,7};
    test.targetChange = 0;
    test.expNumWays = 1;
    cases.push_back(test);

    // Test Case 2
    test.denominations = {5};
    test.targetChange = 9;
    test.expNumWays = 0;
    cases.push_back(test);

    // Test Case 3
    test.denominations = {2,4};
    test.targetChange = 7;
    test.expNumWays = 0;
    cases.push_back(test);

    // Test Case 4
    test.denominations = {1,5};
    test.targetChange = 6;
    test.expNumWays = 2;
    cases.push_back(test);

    // Test Case 5
    test.denominations = {1,5,10,25};
    test.targetChange = 4;
    test.expNumWays = 1;
    cases.push_back(test);

    // Test Case 6
    test.denominations ={1,5,10,25};
    test.targetChange = 5;
    test.expNumWays = 2;
    cases.push_back(test);

    // Test Case 7
    test.denominations = {1,5,10,25};
    test.targetChange = 10;
    test.expNumWays = 4;
    cases.push_back(test);

    // Test Case 8
    test.denominations = {1,5,10,25};
    test.targetChange = 25;
    test.expNumWays = 13;
    cases.push_back(test);

    // Test Case 9
    test.denominations = {2,3,7};
    test.targetChange = 12;
    test.expNumWays = 4;
    cases.push_back(test);

    // Test Case 10
    test.denominations = {2,3,4,7};
    test.targetChange = 7;
    test.expNumWays = 3;
    cases.push_back(test);
    
    for (int i = 0; i < cases.size(); i++) {
        int numWays = numberOfWaysToMakeChange(cases[i].targetChange, cases[i].denominations);
        if(numWays == cases[i].expNumWays){
            cout << "Test Case " << i+1 << " PASSED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected " << cases[i].expNumWays << " Got " << numWays << ")" << endl;
        }
    }

    return 0;
}