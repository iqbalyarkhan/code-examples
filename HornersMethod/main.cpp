//
//  main.cpp
//  HornersMethod
//
//  Created by Iqbal Khan on 4/5/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "RabinKarp.h"

using namespace std;

/**
 - If $x_{i+1}$ is the next string to be tested against our pattern

 - $x_{i}$ is the current string we just tested

 - $t_{i}$ is the text we're removing

 - $R$ is the base of our number (or number of possible characters)

 - $M$ is the length of the pattern

     $
     x_{i+1} = (x_{i} - t_{i}R^{M-1})R + t_{i+M}
     $
 
 */

int main(int argc, const char * argv[]) {
    
    string test = "othersidehellofromthe";
    string pat = "hello";
    long RM = 1;
    int M = 5;
    for (int i = 0; i < M; i++){
        RM = RM * 256;
    }
    
    
    
//    RK rk;
//    cout << rk.GetIndex("hellofromtheothersidestr", "side") << endl;
//    cout << rk.HashFunction("hello", 5) << endl;
    return 0;
}

