//
//  main.cpp
//  UnionFind
//
//  Created by Iqbal Khan on 3/6/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "UnionFind.h"
using namespace std;

int main(int argc, const char * argv[]) {
    UF uf(12);
    uf.Union(4, 9);
    return 0;
}
