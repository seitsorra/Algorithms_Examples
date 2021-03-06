#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template<class T>
void printVector(T v)
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

template<class T>
void printVectorList(T vectorList){
    for(auto vec : vectorList){
        printVector(vec);
    }
}

