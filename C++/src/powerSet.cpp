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
            set.push_back(array.at(j));
        }
    }
    return ret;
}

vector<vector<int>> powerSet(vector<int> array){
    return vector<vector<int>>();
}

int main(){
    vector<vector<int>> got = powerSet_slow(vector<int>{1, 2, 3});

    for(int i=0; i < got.size(); i ++){
        printVector(got.at(i));
        cout << "***************\n";
    }
    char tmp;
    std::cin >> tmp;
    return 0;
}