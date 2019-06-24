/*
    Find three largest numbers

    Write a function that takes in an array of integers and returns a sorted array of the three largest
    integers in the array.
    Note that the function should return duplicate integers if necessary; for example it should
    return a [10, 10, 12] for an array [10, 5, 9, 10, 12]

    Sample Input:   [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
    Sample Output:  [18, 141, 541]
*/

#include "utils.h"

void updateLargest(vector<int>& array, int num);
void shiftAndUpdate(vector<int>& array, int num, int idx);

vector<int> findThreeLargestNums(vector<int> array){
    vector<int> threeLargest (3, std::numeric_limits<int>::min());
    for(int idx = 0; idx < array.size(); idx++){
        updateLargest(threeLargest, array[idx]);
    }
    return threeLargest;
}

void updateLargest(vector<int>& array, int num){
    if(array[2] == std::numeric_limits<int>::min() || num >= array[2]){
        shiftAndUpdate(array, num, 2);
    }
    else if(array[2] == std::numeric_limits<int>::min() || num >= array[1]){
        shiftAndUpdate(array, num, 1);
    }
    else if(array[2] == std::numeric_limits<int>::min() || num >= array[0]){
        shiftAndUpdate(array, num, 0);
    }
}

void shiftAndUpdate(vector<int>& array, int num, int idx){
    for(int i = 0; i <= idx; i++){
        if(i == idx){
            array[idx] = num;
        }
        else{
            array[i] = array[i+1];
        }
    }
}

int main(){
    vector<int> input = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    vector<int> output = {18, 141, 541};

    vector<int> result = findThreeLargestNums(input);
    if(result == output){
        cout << "PASSED" << endl;
    }
    else{
        cout << "FAILED" << endl;
        printVector(result);
    }
}