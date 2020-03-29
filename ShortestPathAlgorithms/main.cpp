//
//  main.cpp
//  ShortestPathAlgorithms
//
//  Created by Iqbal Khan on 3/29/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "Dijkstra.h"
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Digraph dg(6);
    dg.Insert(0, 1, 2);
    dg.Insert(0, 2, 4);
    dg.Insert(1, 2, 1);
    dg.Insert(1, 3, 7);
    dg.Insert(2, 4, 3);
    dg.Insert(3, 5, 1);
    dg.Insert(4, 3, 2);
    dg.Insert(4, 5, 5);
    dg.Print();
    dg.SPADijkstra(0);
    dg.PrintArrays();
    return 0;
}
