#include "../../utils.h"

/**
 * Implement a function void reverse(char* str) that reverses a null terminated string
 */

void reverse(char* str){
    int length = 0;
    while (str[length] != '\0'){length++;}
    length--; // last index is the null terminator

    for(int left = 0; left < length; left++){
        char tmp = str[left];
        str[left] = str[length];
        str[length--] = tmp;
    }
}

int main(){
    char s[] = "abcd\0";
    cout << s << endl;
    reverse(s);
    cout << s << endl;
    return 1;
}