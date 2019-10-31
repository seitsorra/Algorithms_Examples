/*
    Permutations

    Write a function that takes in an array of unique integers and returns an array
    of all permutations of those integers.
    If the input array is empty, your function should returns an empty array.

    Sample Input: [1, 2, 3]
    Sample Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
*/
#include "../utils.h"

vector<int> removeNum(int num, const vector<int>& arr){
    vector<int> ret;

    for(auto val : arr){
        if(num != val){
            ret.push_back(val);
        }
    }
    return ret;
}

void helper(vector<int> arr, vector<int> permutation, vector<vector<int>>& perms){
    if(arr.empty()){
        perms.push_back(permutation);
    }
    else{
        for(int idx = 0; idx < arr.size(); idx++){
            vector<int> newArr = removeNum(arr.at(idx), arr);
            vector<int> newPermutation = permutation;
            newPermutation.push_back(arr.at(idx));
            helper(newArr, newPermutation, perms);
        }
    }
}

vector<vector<int>> getPermutations(vector<int> arr){
    int staticIdx = 0;
    vector<vector<int>> ret;
    helper(arr, {}, ret);
    return ret;
}

struct TestCase{
    vector<vector<int>> result;
    vector<int> input;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.result = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};

    test.input = {1, 2, 3};
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        vector<vector<int>> ret = getPermutations(cases[i].input);
        if(ret == cases[i].result){
            cout << "Test Case " << i+1 << " PASSED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected \n";
            printVectorList(cases[i].result);
            cout << "\nGot\n";
            printVectorList(ret);
        }
    }
    return 0;
}
