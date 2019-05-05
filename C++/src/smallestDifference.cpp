#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    SMALLEST DIFFERENCE

    Write a function that takes in two non-empty arrays of integers. The function should find the pair of numbers (One from the first array,
    one from the second array), whose absolute difference is closest to zero. The function should return an array containing these two
    numbers, with the number from the first array in the first position. Assume there will be only one pair of numbers with the smallest difference.

    Sample Input:
        [-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]
    Output:
        [28, 26]
*/
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
    std::sort(arrayOne.begin(), arrayOne.end());
    std::sort(arrayTwo.begin(), arrayTwo.end());

    int lowestDff = -1;
    int idxA = 0;
    int idxB = 0;
    vector<int> ret;

    while(idxA < arrayOne.size() && idxB < arrayTwo.size()){

        int first = arrayOne[idxA];
        int second = arrayTwo[idxB];

        int currentPairDiff = std::abs(arrayOne[idxA] - arrayTwo[idxB]);

        if(first < second){
            currentPairDiff = second - first;
            idxA++;
        }
        else if(second < first){
            currentPairDiff = first - second;
            idxB++;
        }
        else{ // Difference is 0 so we are done
            return vector<int> {first, second};
        }

        if (lowestDff == -1 || currentPairDiff < lowestDff){
            ret = {first, second};
            lowestDff = currentPairDiff;
        }
        
    }
    return ret;
}

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i == v.size() - 1){
            cout << endl;
        }
        else{
            cout << " , ";
        }
    }
}

struct testCase
{
    string name;
    vector<int> first;
    vector<int> second;
    vector<int> result;
};


int main()
{
    vector<testCase> testCases;
    testCase test;
    test.name = "Test Case 1";
    test.first = {-1,5,10,20,3};
    test.second = {26,134,135,15,17};
    test.result = {20,17};
    testCases.push_back(test);

    test.name = "Test Case 2";
    test.first = {-1,5,10,20,28,3};
    test.second = {26,134,135,15,17};
    test.result = {28,26};
    testCases.push_back(test);

    test.name = "Test Case 3";
    test.first = {10, 0, 20, 25};
    test.second = {1005,1006,1014,1032,1031};
    test.result = {25,1005};
    testCases.push_back(test);

    test.name = "Test Case 4";
    test.first = {10, 0, 20, 25, 2200};
    test.second = {1005,1006,1014,1032,1031};
    test.result = {25,1005};
    testCases.push_back(test);

    test.name = "Test Case 5";
    test.first = {10, 0, 20, 25, 2000};
    test.second = {1005,1006,1014,1032,1031};
    test.result = {2000,1032};
    testCases.push_back(test);

    test.name = "Test Case 6";
    test.first = {240,124,86,111,2,84,954,27,89};
    test.second = {1,3,954,19,8};
    test.result = {954,954};
    testCases.push_back(test);

    test.name = "Test Case 7";
    test.first = {0,20};
    test.second = {21,-2};
    test.result = {20,21};
    testCases.push_back(test);

    test.name = "Test Case 8";
    test.first = {10,1000};
    test.second = {-1441,-124,-25,1014,1500,660,410,245,530};
    test.result = {1000,1014};
    testCases.push_back(test);

    test.name = "Test Case 9";
    test.first = {10,1000,9124,2142,59,24,596,591,124,-123};
    test.second = {-1441,-124,-25,1014,1500,660,410,245,530};
    test.result = {-123,-124};
    testCases.push_back(test);

    test.name = "Test Case 10";
    test.first = {10,1000,9124,2142,59,24,596,591,124,-123,530};
    test.second = {-1441,-124,-25,1014,1500,660,410,245,530};
    test.result = {530,530};
    testCases.push_back(test);

    for(int i = 0; i < testCases.size(); i++){
    //for(int i = 4; i < 5; i++){
        std::cout << testCases[i].name << " --> ";
        if(testCases[i].result == smallestDifference(testCases[i].first, testCases[i].second)){
            cout << "PASSED" << endl;
        }
        else{
            cout << "FAILED" << endl;
        }
    }

    return 0;
}