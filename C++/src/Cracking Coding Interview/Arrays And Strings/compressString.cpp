/*
    Implement a method to perform basic string compression using the counts of repeasted characters.

    If the "compressed" string would become longer than the original string then simply return the original

    Case 1:
    ------
    Input:  "aabcccccaaa"
    Output: "a2b1c5a3"

    Case 2:
    ------
    Inout:  "aabcdeff"
    Output: "aabcdeff" since "a2b1c1d1e1f2" would be longer
*/

#include "../../utils.h"

string compressString(string str){
    string comppressed;
    if(str.empty()){
        return comppressed;
    }

    char cur = str[0];
    int counter = 1;
    for(int i= 1; i < str.length(); i++){
        if(str[i] == cur){
            counter++;
        }
        else{
            comppressed.push_back(cur);
            comppressed.append(to_string(counter).c_str());
            cur = str[i];
            counter = 1;
        }
    }
    //Add last char set here because the above loop will go out without saving the last set of repeated chars
    comppressed.push_back(cur);
    comppressed.append(to_string(counter).c_str());
    return (comppressed.length() < str.length()) ? comppressed : str;
}

int main(){
    string a = "aabcccccaaabc";
    cout << "Compressed of (" << a << ") is :" << compressString(a) << endl;
    return 1;
}