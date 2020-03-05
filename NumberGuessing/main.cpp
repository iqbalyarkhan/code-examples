//
//  main.cpp
//  NumberGuessing
//
//  Created by Iqbal Khan on 3/3/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int k = 1;
    int n = 12;
   int ans = 0;
   for (int i = 0; i <= n; i++){
       int num = i;
       while (true){
           int currRem = num % 10;
           if (currRem == k){
               ans++;
           }
           num = num/10;
           if (num == 0){
               break;
           }
       }
   }
   
   return ans;
//    int upper = 0;
//    int lower = 0;
//    int guess = 0;
//    cin >> upper >> lower;
//    while (cin){
//        int num;
//        cin >> num;
//        cout << "Entered input " << num << endl;
//    }
    
//    return 0;
}
