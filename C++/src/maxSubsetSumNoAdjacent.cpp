/*
Maximum Subset Sum With No Adjacent Elements

Write a function that takes in an array of positives integers and returns
an integer representing the maximum sum of non-adjacent elements in the array.
If a sum cannot be generated, the function should return 0.

Sample input:  [75, 105, 120, 75, 90, 135]
Sample output: 330 - [75, 120, 135]

*/

#include "utils.h"
/*
    Here we will make use of dynamic programming and build another array with maximum sum as we traverse the provided one.

    So for array:        [75, 105, 120, 75, 90, 135]
    Use    maxSumArray:  [75, 105, 0 , 0 , 0 , 0]

    Since we cannot use the adjacent values then for each index in the provided array we can use the following formula to determine
    max sum:

        sum = max(maxSumArray[idx-1], (maxSumArray[idx-2]+array[idx]))
    
    Also to make things easier we can do the following:
        - if array has size less than 2 then no sum can be generated so return 0
        - populate the first two index of dynamic max sum with respective indexs of the provided array and start iterating at (idx=2)
*/
int maxSubsetSumNoAdjacent(vector<int> array){
    if(array.size() <= 2){
        return 0;
    }
    vector<int> maxSum(array.size());
    maxSum.at(0) = (array[0]);
    maxSum.at(1) = (array[1]);

    int idx = 2;
    while (idx < array.size()){
        maxSum[idx] = max(maxSum[idx-1], (maxSum[idx-2]+array[idx]));
        idx++;
    }
    return maxSum[array.size()-1];
}

struct TestCase{
    vector<int> v;
    int sum;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.v = {75, 105, 120, 75, 90, 135};
    test.sum = 330;
    cases.push_back(test);

    // Test Case 2
    test.v = {1};
    test.sum = 0;
    cases.push_back(test);

    // Test Case 3
    test.v = {1, 2};
    test.sum = 0;
    cases.push_back(test);

    // Test Case 4
    test.v = {1,2,3};
    test.sum = 4;
    cases.push_back(test);

    // Test Case 5
    test.v = {1,15,3};
    test.sum = 15;
    cases.push_back(test);

    // Test Case 6
    test.v = {10,5,20,25,15,5,5,15,3,15,5,5,15};
    test.sum = 90;
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        int maxSum = maxSubsetSumNoAdjacent(cases[i].v);
        if(maxSum == cases[i].sum){
            cout << "Test Case " << i+1 << " PASED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected " << cases[i].sum << " Got " << maxSum << ")" << endl;
        }
    }
    return 0;
}