#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

bool isPalindrome(int num){
    while (num != 0){
        int numberOfDigits = log10(num);
        int divideBy = pow(10,numberOfDigits);
        int msb = num/divideBy;
        int lsb = num % 10;
        if (! (msb == lsb))
            return false;
        num = num - (msb * divideBy);
        num = num/10;
    }
    return true;
}

bool isPalindromeReversed(int num){
    int ans = 0;
    int origNum = num;
    while (num != 0){
        ans = (ans * 10) + num % 10;
        num = num/10;
    }
    
    return (ans == origNum);
}

int main(int argc, const char * argv[]) {
    
    int num = 0;
    while (num != -1){
        cout << "Enter a number or -1 to quit: " << endl;
        cin >> num;
        if (num == -1)
            break;
        cout << isPalindromeReversed(num) << endl;
        cout << isPalindrome(num) << endl;
    }
    
    return 0;
}
