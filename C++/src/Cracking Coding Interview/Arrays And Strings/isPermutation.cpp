/*
    Given two strings implement a method to find out whether one string is a
    permutation of the other

    QUESTIOSN (to ask interviewer):
        - is permutation case sensiteve (i.e. "dog" and "God" are the same?)
        - is white spacing considered?


    We are going to consider that permutation is case sensitive and white spaces matter 
*/

#include "../../utils.h"

bool isStringPerm(string a, string b){
    if(a.length() != b.length()){
        return false;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
}

bool isStringPerm_ver2(string a, string b){
    if(a.length() != b.length()){
        return false;
    }

    int allChars[256] = {0};

    for(int i = 0; i < a.length(); i++){
        allChars[(int)a.at(i)]++;
    }
    for(int i = 0; i < b.length(); i++){
        if(--allChars[(int)b.at(i)] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    string a = "dog";
    string b = "god";

    if(isStringPerm_ver2(a, b)){
        cout << a << " and " << b << " are perms\n";
    }
    else{
        cout << a << " and " << b << " not perms\n";
    }

    if(isStringPerm(a, b)){
        cout << a << " and " << b << " are perms\n";
    }
    else{
        cout << a << " and " << b << " not perms\n";
    }
    return 0;
}