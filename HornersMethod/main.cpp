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

int main(int argc, const char * argv[]) {
    RK rk;
    cout << rk.GetIndex("hellofromtheothersidestr", "side") << endl;
    return 0;
}

