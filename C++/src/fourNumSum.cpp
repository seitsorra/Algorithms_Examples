/*
    Four Num Sum

    Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum.
    The function should find all the quadraplets in the array that sum up to the target sum and return a two dimenstional array 
    of all theses quadraplets in no particular order.
    If no four numbers sum up to the target sum, the function should return an empty array.

    Sample Input: [7, 6, 4, -1, 1, 2], 16
    Sample Outpu: [[7,6,4,-1], [7, 6, 1, 2]]
 */

#include "utils.h"

// Average: O(n^2) time | O(n^2) space
// Worst:   O(n^3) time | O(n^2) space
vector<vector<int>> fourNumberSum(vector<int> array, int target)
{
    vector<vector<int>> quadruplets;

    // This contianer will be used to keep track of all the pair sums as we traverse the array index by index
    unordered_map<int, vector<vector<int>>> allPairSums;

    // Main loop; here we purposely avoid first round and start directly on index 1
    // since we know initially wont have an accumulated pair sums
    for (int mainIdx = 1; mainIdx < array.size() - 1; mainIdx++){

        // In this for loop we check all the indexes right to our main index and for each pair we check the
        // whether it complement to the target exists in our accumulated all pair sums
        for (int j = mainIdx + 1; j < array.size(); j++){
            // Current sum of this pair
            int currentSum = array[mainIdx] + array[j];

            // Here calculate the difference to target sum so we can search for it in our available pair sums of the arraya
            int diff = target - currentSum;

            // If a pair summing up to 'diff' exists in our container then we got ourselves a qudruplet
            if (allPairSums.find(diff) != allPairSums.end()){
                for (auto set : allPairSums[diff]){
                    quadruplets.push_back(vector<int>{array[j], array[mainIdx], set[0], set[1]});
                }
            }
        }

        // Second for loop generates all pairs of indexes to the left of mainIdx with itself
        // NOTE: here need to be careful to not override any existing pair with same sum
        //       In order to avoid that we keep a list of pair for each sum
        for (int k = 0; k < mainIdx; k++){
            int sum = array[k] + array[mainIdx];
            if (allPairSums.find(sum) == allPairSums.end()) {
                allPairSums[sum] = vector<vector<int>>{vector<int>{array[k], array[mainIdx]}};
            }
            else{
                allPairSums.at(sum).push_back(vector<int>{array[k], array[mainIdx]});
            }
        }
    }

    return quadruplets;
}

int main()
{
    vector<int> input = {7, 7 , 2,0};// {7, 6, 4, -1, 1, 2};
    int target = 16;
    vector<vector<int>> results = fourNumberSum(input, target);
    for (auto it : results) {
        printVector(it);
    }
    cout << "Press enter to continue...";
    cin.get();

    return 0;
}