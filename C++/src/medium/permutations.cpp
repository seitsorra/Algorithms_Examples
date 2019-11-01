/*
    Permutations

    Write a function that takes in an array of unique integers and returns an array
    of all permutations of those integers.
    If the input array is empty, your function should returns an empty array.

    Sample Input: [1, 2, 3]
    Sample Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
*/
#include "../utils.h"

void swap(int idx1, int idx2, vector<int>* array){
    int tmp = array->at(idx1);
    array->at(idx1) = array->at(idx2);
    array->at(idx2) = tmp;
}

// This helper function will be called recursively that creates a permutation set for each index of the array
// Upper Bound : O(n^2 * n!) time | O(n*n!) space
// Roughly     : O(n*n!) time | O(n*n!) space
void permutationHelper(vector<int> arr, vector<int> permutation, vector<vector<int>>& perms){
    // When we hit an empty array then we have got a permutation set, so update the list
    if(arr.empty()){
        perms.push_back(permutation);
    }
    // Otherwise for each index of the array, copy all elements excpect the current index into a new array
    // and add the current index value to the permutation set (need to copy it because it is a recursive function)
    else{
        for(int idx = 0; idx < arr.size(); idx++){
            vector<int> newArr;
            newArr.insert(newArr.end(), arr.begin(), arr.begin() + idx);
            newArr.insert(newArr.end(), arr.begin() + idx + 1, arr.end());

            vector<int> newPermutation = permutation;
            newPermutation.push_back(arr.at(idx));

            permutationHelper(newArr, newPermutation, perms);
        }
    }
}

// O(n*n!) time | O(n*n!) space
void permutationHelperInPlace(int i, vector<int>* array, vector<vector<int>>* perms){
    if(i == array->size()-1){
        perms->push_back(*array);
    }
    else
    {
        for(int j = i; j < array->size(); j++){
            swap(i, j, array);
            permutationHelperInPlace(i+1, array, perms);
            swap(i, j, array);
        }
    }
}

vector<vector<int>> getPermutations(vector<int> arr){
    vector<vector<int>> ret;
    permutationHelperInPlace(0, &arr, &ret);
    //permutationHelper(arr, {}, ret);
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
        for(auto it : ret){
            std::sort(it.begin(), it.end());
        }
        for(auto it : test.result){
            std::sort(it.begin(), it.end());
        }
        std::sort(ret.begin(), ret.end());
        std::sort(test.result.begin(), test.result.end());

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
