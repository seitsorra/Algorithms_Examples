/*
    Power Set

    Write a function that takes in an array of unique integers and returns its power set.
    The power set P(x) of a set X is the set of all subsets of X.

    For example the powerset of [1,2] is [[],[1],[2],[1,2]]
    NOTE: the sets in the powerset do not need to be in any particular order

    Sample Input: [1,2,3]
    Sample Output: [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
 */

#include "utils.h"

//This algorithm will run at O(N^2) time and O(N) space
vector<vector<int>> powerSet_slow(vector<int> array){
    vector<vector<int>> ret;
    ret.push_back(vector<int>()); // there will always be an empty set
    for (int i = 0; i < array.size(); i++){
        ret.push_back(vector<int>{array.at(i)});
    }
    for (int i = 0; i < array.size()-1; i++){
        vector<int> set;
        set.push_back(array.at(i));
        for(int j = i+1; j < array.size(); j++){
            ret.push_back(vector<int>{array.at(i), array.at(j)});
        }
    }
    if(!array.empty()){
        ret.push_back(array);
    }
    return ret;
}

// mathematically we know that the total number of subsets would be 2^n
// and in average the length of subsets will be n/2
// time & space complexity is O(2^n * n)
vector<vector<int>> powerSet(vector<int> array){

    // We know that the power set always has an empty set
    vector<vector<int>> ret = {{}};

    // here we go iterativaly to the source array and for each subset in 'ret' we add new ones by appending the new index
    for(int i = 0; i < array.size(); i++){
        int curSubsetSize = ret.size();
        for(int j=0; j<curSubsetSize; j++){
            vector<int> tmp = ret.at(j);
            tmp.push_back(array.at(i));
            ret.push_back(tmp);
        }
    }
    return ret;
}

// Recursice function
vector<vector<int>> powerSetHelper(vector<int> array, int idx){
    if(idx < 0){
        return vector<vector<int>> {{}};
    }

    int element = array[idx];
    vector<vector<int>> subsets = powerSetHelper(array, idx-1);
    int length = subsets.size();
    for(int i = 0; i < length; i++){
        vector<int> tmp = subsets.at(i);
        vector<int> newSubset = tmp;
        newSubset.push_back(element);
        subsets.push_back(newSubset);
    }
    return subsets;
}

vector<vector<int>> powerSet_recursive(vector<int> array){
    return powerSetHelper(array, array.size()-1);
}

int main(){
    vector<vector<int>> got = powerSet_recursive(vector<int>{1, 2, 3});

    for(int i=0; i < got.size(); i ++){
        printVector(got.at(i));
        cout << "***************\n";
    }
    char tmp;
    std::cin >> tmp;
    return 0;
}