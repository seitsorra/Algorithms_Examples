#include "../../utils.h"

/**
 * Write a method to replace all spaces in a string with '%20'
 * You may assume that the string has sufficient space at the end of string to hold additional characters.
 * and you are given the true lenth of the string.
 * 
 * Example:
 * 
 * Input:  "Mr John Smith    " 13
 * Output: "Mr%20John%20Smith" 13
 */


/**
 * Brainstorm:
 * - clearly this can be solved if we where to iterate character by character and append them in a new string and of course space replaces to %20
 *      - but that would mean O(n) memory and O(n) time
 *  - alternatively we can do the replacement in place by starting at the end of string moving characters all the way at the end
 */

void replaceSpaces(string& str, int len){
    
    // First find the last non-space characters
    int left = len - 1;
    int right = str.length() - 1; // keeps track index of the characters from the right side of the string

    while(left >= 0){
        if (str[left] == ' '){
            str[right--] = '0';
            str[right--] = '2';
            str[right--] = '%';
        }
        else{
            str[right--] = str[left];
        }
        left--;
    }
}

int main(){
    string s = "Mr John Smith    ";
    replaceSpaces(s, 13);
    cout << s << endl;
    return 1;
}