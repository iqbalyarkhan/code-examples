//
//  main.cpp
//  PrimitiveTypes
//
//  Created by Iqbal Khan on 4/11/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
//#include <bitset>

using namespace std;

void BKAlgo(int num){
    int ans = 0;
    int count = 0;
    while (num != 0){
        count++;
        num = (num & (num - 1));
        ans++;
    }
    if (ans % 2 == 0)
        cout << "Even parity: " << ans << " with "<< count << " iterations." <<endl;
    else
        cout << "Odd parity: " << ans << " with "<< count << " iterations." <<endl;
}

void getParity(int num){
    int ans = 0;
    int count = 0;
    while (num != 0){
        count++;
        ans += num & 1;
        num = num >> 1;
    }
    
     if (ans % 2 == 0)
         cout << "Even parity: " << ans << " with "<< count << " iterations." <<endl;
     else
         cout << "Odd parity: " << ans << " with "<< count << " iterations." <<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << (9 & 1) << endl;
//    cout << (9 | 1) << endl;
//    bool a = 00000000;
//    bool b = 10000000;
//    if (a == true){
//        cout << "a is true!" << endl;
//    } else {
//        cout << "a is false!" << endl;
//    }
//
//    bitset<8> temp('a');
//    cout << temp << endl;
    
    getParity(21);
    BKAlgo(21);
    
    return 0;
}
