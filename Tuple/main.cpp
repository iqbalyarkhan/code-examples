//
//  main.cpp
//  Tuple
//
//  Created by Iqbal Khan on 3/26/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    auto t = make_tuple(2,3,4);
    cout << get<0>(t) << endl;
    
    return 0;
}
