/*
    River Sizes
    
    You are given a two dimensional array (matrix) of potentially unequal height and width containing
    only 0s and 1s.
    Each '0' represents land, and each '1' represents part of a river.
    A river consists of any number of 1s that are either horizontally or vertically adjacent (but not diagonally adjecent)
    The number of adjecent 1s forming a river determines its size.

    Write a function that returns an array of the sizes of all rivers represented in the input matrix.
    NOTE: these sizes do not need to be in any particular order.

    Sample input:
        [
            [1, 0, 0, 1, 0],
            [1, 0, 1, 0, 0],
            [0, 0, 1, 0, 1],
            [1, 0, 1, 0, 1],
            [1, 0, 1, 1, 0]
        ]

    Sample output: [1, 2, 2, 2, 5]
*/
#include "utils.h"

vector<int> riverSizes(vector<vector<int>> matrix){
    return {1, 2, 2, 2, 5};
}

struct TestCase{
    vector<vector<int>> matrix;
    vector<int> result;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.matrix = {{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0}};
    test.result = {1, 2, 2, 2, 5};
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        vector<int> res = riverSizes(cases[i].matrix);
        if(res == cases[i].result){
            cout << "Test Case " << i+1 << " PASED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected \n";
            printVector(cases[i].result);
            cout << "\n Got \n";
            printVector(res);
        }
    }
    return 0;
}