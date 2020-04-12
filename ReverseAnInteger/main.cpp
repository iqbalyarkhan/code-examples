//
//  main.cpp
//  ReverseAnInteger
//
//  Created by Iqbal Khan on 4/11/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int Reversed(int num){
    int ans = 0;
    bool wasNeg = false;
    if (num < 0){
        wasNeg = true;
        num = num * (-1);
    }
    while (num != 0){
        ans = (ans * 10) + num % 10;
        num = num/10;
    }
    if (wasNeg)
        ans = ans * -1;
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int num = 0;
    while (num != -1){
        cout << "Enter a number or -1 to quit: " << endl;
        cin >> num;
        if (num == -1)
            break;
        cout << Reversed(num) << endl;
    }
    
    return 0;
}
