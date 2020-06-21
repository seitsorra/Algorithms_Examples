#include "../../utils.h"

/**
 * Write a method to perform basic string compression using the counts of repeated characters
 * 
 * For example, the string aabcccccaaa would become a2b1c5a3.
 * 
 * If the compressed string would not become smaller than the original one, your method would return the original string
 */


string compress(const string& str){
    char curChar = '\0';
    int length = 0;
    string compressed;

    for(int idx = 0; idx < str.size(); idx++){
        if (curChar == '\0'){
            curChar = str[idx];
            length++;
        }
        else if (str[idx] == curChar){
            length++;
        }
        else{
            compressed.push_back(curChar);
            compressed.append(to_string(length));
            length = 1;
            curChar = str[idx];
        }

        // Always save the last iteration
        if(idx == str.size()-1){
            compressed.push_back(curChar);
            compressed.append(to_string(length));
        }
    }

    return str.size() > compressed.size() ? compressed : str;
}


int main(){
    string orig = "aabcccccaaa";
    cout << "String " << orig << " compressed to " << compress(orig) << endl;
    return 1;
}