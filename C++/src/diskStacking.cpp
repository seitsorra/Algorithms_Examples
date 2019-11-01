/*
    Disk Stacking

    You are given a non-empty array of arrays. Each sub array holds three integers and represents a disk.
    These integers denote each disk's width, depth and height, respectively.

    Your goal is to stack up the disks and to maximize the total height of the stack.
    A disk must have strictly smaller width, depth and height than any other disk below it.

    Write a function that returns an array of disks in the final stack, starting with the top disk and ending with the bottom disk.
    NOTE: You cannot rotate disks; in other words, the integers in each subarray must represent [width, depth, height] at all times.
    
    Assume there will be only one stack with the greatest total height


    Sample Input:  [[2, 1, 2], [3, 2, 3], [2, 2, 8], [2, 3, 4], [1, 3, 1], [4, 4, 5]]
    Sample Output: [[2, 1, 2], [3, 2, 3], [4, 4, 5]]
 */

#include "utils.h"
bool validArgs(const vector<int>& o, const vector<int>& c){
    return o[0] < c[0] && o[1] < c[1] && o[2] < c[2];
}

vector<vector<int>> buildSequences(const vector<vector<int>>& disks, const vector<int>& sequences, int currentIdx){
    vector<vector<int>> ret;
    while (currentIdx != -1){
        ret.push_back(disks[currentIdx]);
        currentIdx = sequences[currentIdx];
    }
    // the above will construct a sequence [bottomDisk, secondBottom, thirdBottom ... topDisk]
    // but we want it to be top down. So need to reverse the list
    std::reverse(ret.begin(), ret.end());
    return ret;
}

// O(n^2) time | O(n) space
vector<vector<int>> diskStacking(vector<vector<int>> disks){
    // Sort the disks by their heights
    sort(disks.begin(), disks.end(), [](const vector<int>& leftDisk, const vector<int>& rightDisk){
        return leftDisk[2] < rightDisk[2];
    });

    // initialize a array that will hold maximum height we can form for each index of the array
    // such that the index is set to the bottom
    vector<int> maxHeights;
    for(auto it : disks){
        maxHeights.push_back(it[2]);
    }

    // used to keep track of indexes used to build disk tower
    vector<int> sequences(disks.size(), -1);
    int maxHeightIdx = 0;

    for(int i = 1; i < disks.size(); i++){
        vector<int> currentDisk = disks[i];
        for(int j = 0; j < i; j++){
            vector<int> otherDisk = disks[j];
            if(validArgs(otherDisk, currentDisk)){
                // Here we only update in the case where the current disk with another one have a height
                // bigger than what the maximum height currently is in the index of current disk
                if(maxHeights[j] + currentDisk[2] > maxHeights[i]){
                    maxHeights[i] = maxHeights[j] + currentDisk[2];
                    sequences[i] = j; // update the sequences with the next top disk's index
                }
            }
        }
        if(maxHeights[i] > maxHeights[maxHeightIdx]){
            maxHeightIdx = i;
        }
    }

    return buildSequences(disks, sequences, maxHeightIdx);
}

struct TestCase{
    vector<vector<int>> input;
    vector<vector<int>> result;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.input = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 3, 1}, {4, 4, 5}};
    test.result = {{2, 1, 2}, {3, 2, 3}, {4, 4, 5}};
    cases.push_back(test);

    // Test Case 2
    test.input = {{2, 1, 2}};
    test.result = {{2, 1, 2}};
    cases.push_back(test);

    // Test Case 3
    test.input = {{2, 1, 2}, {3, 2, 3}};
    test.result = {{2, 1, 2}, {3, 2, 3}};
    cases.push_back(test);

    // Test Case 4
    test.input = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}};
    test.result = {{2, 2, 8}};
    cases.push_back(test);

    // Test Case 5
    test.input = {{2, 1, 2}, {3, 2, 3}, {2, 3, 4}};
    test.result = {{2, 1, 2}, {3, 2, 3}};
    cases.push_back(test);

    // Test Case 6
    test.input = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8},{2, 3, 4}, {2, 2, 1}, {4, 4, 5}};
    test.result = {{2, 1, 2}, {3, 2, 3}, {4, 4, 5}};
    cases.push_back(test);

    // Test Case 7
    test.input = {{2, 1, 2}, {3, 2, 5}, {2, 2, 8}, {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};
    test.result = {{2, 3, 4}, {4, 4, 5}};
    cases.push_back(test);

    // Test Case 8
    test.input = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 2, 1}, {4, 4, 5}, {1, 1, 4}};
    test.result = {{1, 1, 4}, {2, 2, 8}};
    cases.push_back(test);

    // Test Case 9
    test.input = {{3, 3, 4}, {2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {5, 5, 6}, {1, 2, 1}, {4, 4, 5}, {1, 1, 4}, {2, 2, 3}};
    test.result = {{2, 2, 3}, {3, 3, 4}, {4, 4, 5}, {5, 5, 6}};
    cases.push_back(test);

    // Test Case 10
    test.input = {};
    test.result = {};
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        vector<vector<int>> ret = diskStacking(cases[i].input);
        if(ret == cases[i].result){
            cout << "Test Case " << i+1 << " PASSED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! \nExpected\n";
            printVectorList(cases[i].result);
            cout << "\nGot\n";
            printVectorList(ret);
        }
    }
    return 0;
}