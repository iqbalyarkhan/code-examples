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
    uf.Union(1, 0);
    uf.Union(5, 6);
    uf.Union(5, 10);
    uf.Union(4, 3);
    uf.Union(3, 2);
    uf.Union(7, 1);
    uf.Union(4, 5);
    uf.Union(5, 10);
    uf.Union(11, 8);
    uf.Union(11, 1);
    uf.Union(11, 10);
    cout << "10's root is: " << uf.FindRoot(10) << " and 2's root is: " << uf.FindRoot(2) << endl;
    uf.PrintAllVectors();
    return 0;
}
