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

vector<vector<int>> diskStacking(vector<vector<int>> disks){
    vector<vector<int>> stackedDisks;

    return stackedDisks;
}

int main(){
    vector<vector<int>> disks = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 3, 1}, {4, 4, 5}};
    for(auto disk : diskStacking(disks)){
        printVector(disk);
    }
    return 0;
}