#include "../../utils.h"

/**
 * Given two string find whether one is a permutation of the other
 */

// Well first method would be sort the strings and compare
bool isPermutation(string& str1, string& str2){
    if(str1.length() != str2.length()){
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    int idx = 0;
    while (idx++ != str1.length()){
        if(str1[idx] != str2[idx]){
            return false;
        }
    }
    return true;
}


int main(){
    string s1 = "b";
    string s2 = "b";

    cout << isPermutation(s1, s2) << endl;
    return 1;
}