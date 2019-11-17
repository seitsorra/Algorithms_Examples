/*
    Implement a function 'void reverse(char* str)' which reverses
    a null terminated string
*/
#include "../../utils.h"

void reverse(char* str){
    
    // Figure out the length of string
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    char tmp;
    for(int left = 0, right = length-1; left != right; left++){
        tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        right--;
    }

    for(int i = 0; i < length; i++){
        cout << str[i];
    }
    cout << endl;
   
}

int main(){
    char str[] = "abcde\0";

    reverse(str);
}