#include "../../utils.h"

/*
    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use other data structures?
*/

void test(int a[]){
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << endl;
}

// Runs in O(n) time | O(n) space
bool hasUniqueCharacters(string s){
    bool allChars[256];
    memset(allChars, 0, 256*sizeof(bool));
    //int *a = new int[5]{1,2, 3, 4, 5};

    for(int i = 0; i < s.length(); i++){
        int c = s.at(i);
        if(allChars[c]){
            return false;
        }
        allChars[c] = true;
    }
    return true;
}

// Works for strings with alphabet a-z
// Runs in O(n) time | O(1) space
bool hasUniqueChars(string s){
    int check = 0;
    for(int i = 0; i < s.length(); i++){
        int c = s.at(i) - 'a';
        if(check & (1 << c)){
            return false;
        }
        check |= (1 << c);
    }
    return true;
}

int main(){
    string test = "abcderfZGUIOPsnM";
    if(hasUniqueChars(test)){
        cout << "string (" << test << ") has unique characters";
    }
    else{
        cout << "string (" << test << ") does not have unique characters";
    }
}