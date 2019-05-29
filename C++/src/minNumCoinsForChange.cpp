/*
    Min Number Of Coins For Change
    ------------------------------

    Given an array of positive integers representing coin denominations and a single non-negative integer
    representing a target amount of money, implement a function that returns the smallest number of coins
    needed to make change for that target amount using the coin denominations.
    
    Note that an unlimited amount of coins is at your disposal. If it is impossible to make change for the
    target amount, return -1.

    Sample Input:   7, [1, 5, 10]
    Sample output:  3 (2x1 + 1x5)
*/

#include "utils.h"

// O(target*denoms) time | O(target+1) space
int minNumberOfCoinsForChange(int target, vector<int> denoms){

    vector<int> minWays (target+1, std::numeric_limits<int>::max());
    minWays[0] = 0;
    int toCompare;
    std::sort(denoms.begin() , denoms.end());
    for(int denom : denoms){
        for(int dollarAmount = 0; dollarAmount < minWays.size(); dollarAmount++){
            if(denom <= dollarAmount){

                if(minWays[dollarAmount-denom] == std::numeric_limits<int>::max()){
                    toCompare = minWays[dollarAmount - denom];
                }
                else{
                    toCompare = 1 + minWays[dollarAmount - denom];
                }
                
                minWays[dollarAmount] = min(minWays[dollarAmount], toCompare);
                ///TODO: Why can't we simple do the following ??? (Python works!!!)
                //minWays[dollarAmount] = min(minWays[dollarAmount], 1 + minWays[dollarAmount - denom]);

            }
        }
    }
    if(minWays[target] == std::numeric_limits<int>::max()){
        return -1; // It means we couldn't user coin denominations to make the requested change
    }
    return minWays[target];
}

// Unit Test
struct TestCase{
    vector<int> denoms;
    int targetChange;
    int minWays;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.denoms = {1, 2, 3};
    test.targetChange = 0;
    test.minWays = 0;
    cases.push_back(test);

    // Test Case 2
    test.denoms = {2, 1};
    test.targetChange = 3;
    test.minWays = 2;
    cases.push_back(test);

    // Test Case 3
    test.denoms = {1, 5, 10};
    test.targetChange = 4;
    test.minWays = 4;
    cases.push_back(test);

    // Test Case 4
    test.denoms = {1, 5, 10};
    test.targetChange = 7;
    test.minWays = 3;
    cases.push_back(test);

    // Test Case 5
    test.denoms = {1, 5, 10};
    test.targetChange = 10;
    test.minWays = 1;
    cases.push_back(test);

    // Test Case 6
    test.denoms = {1, 5, 10};
    test.targetChange = 11;
    test.minWays = 2;
    cases.push_back(test);

    // Test Case 7
    test.denoms = {1, 5, 10};
    test.targetChange = 24;
    test.minWays = 6;
    cases.push_back(test);

    // Test Case 8
    test.denoms = {1, 5, 10};
    test.targetChange = 25;
    test.minWays = 3;
    cases.push_back(test);

    // Test Case 9
    test.denoms = {2, 4};
    test.targetChange = 7;
    test.minWays = -1;
    cases.push_back(test);

    // Test Case 10
    test.denoms = {3, 7};
    test.targetChange = 7;
    test.minWays = 1;
    cases.push_back(test);

    // Test Case 11
    test.denoms = {3, 5};
    test.targetChange = 9;
    test.minWays = 3;
    cases.push_back(test);

    // Test Case 12
    test.denoms = {3, 4, 5};
    test.targetChange = 9;
    test.minWays = 2;
    cases.push_back(test);

    // Test Case 13
    test.denoms = {39, 45, 130, 40, 4, 1};
    test.targetChange = 135;
    test.minWays = 3;
    cases.push_back(test);

    // Test Case 14
    test.denoms = {39, 45, 130, 40, 4, 1, 60, 75};
    test.targetChange = 135;
    test.minWays = 2;
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        int numWays = minNumberOfCoinsForChange(cases[i].targetChange, cases[i].denoms);
        if(numWays == cases[i].minWays){
            cout << "Test Case " << i+1 << " PASSED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected " << cases[i].minWays << " Got " << numWays << ")" << endl;
        }
    }

    return 0;
}