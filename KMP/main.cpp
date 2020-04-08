//
//  main.cpp
//  KMP
//
//  Created by Iqbal Khan on 4/7/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#include "KMP.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    KMP kmp;
    auto ans = kmp.GetIndex("kdddababdddsababa", "abab");
    cout << ans.size() << endl;
    return 0;
}
