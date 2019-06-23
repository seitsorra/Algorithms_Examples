/*
    Nth Fibonaci

    The fibonaci sequence is defined as follows: the first number if the sequence is 0 the second is 1, and the
    nth number is is the sum of the (n-1)th + (n-2)th.

    Write a function that takes in an integer and returns the nth Fibonacci number.

    Sample Input  : 6
    Sample Output : 5 [0, 1, 1, 2, 3, 5]
*/

#include "utils.h"

// O(n) time - O(1) space
int getNthFib(int n){
    if(n == 1){
        return 0;
    }
    else if(n == 2 || n == 3){
        return 1;
    }
    else{
        int preLast = 1;
        int last = 1;
        int current;
        for(int i = 3; i < n; i++){
            current = preLast + last;
            preLast = last;
            last = current;
        }
        return current;
    }
}

int main(){
    cout << "6th Fib " << getNthFib(6) << endl;
}