/*
    Write a method to replace all spaces in a string with '%20'.
    You may assume the string has sufficient space at the end of the string to hold the additional characters, 
    and that you are given the "true" length of the string.

    EXAMPLE:
    Input:  "Mr John Smith    " 13
    Output: "Mr%20John%20Smith"
*/

#include "../../utils.h"
void replaceSpace(char* str, int len){
    // When go backward in original string and start transferring characters back to string
    int lastChar = len-1;
    while(str[lastChar] == ' ') lastChar--;
    for(int i = len-1; i >= 0; i--){
        if(str[lastChar] == ' '){
            str[i--] = '0';
            str[i--] = '2';
            str[i] = '%';
        }
        else{
            str[i] = str[lastChar];
        }
        lastChar--;
    }
}

int main(){
    char str[] = "Mr John Smith    ";
    replaceSpace(str, 17);
    cout << str << endl;
    return 1;
}