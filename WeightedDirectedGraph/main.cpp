//
//  main.cpp
//  WeightedDirectedGraph
//
//  Created by Iqbal Khan on 3/29/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Digraph.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Digraph dg(8);
    dg.Insert(5, 4, 0.35);
    dg.Insert(4, 7, 0.37);
    dg.Insert(5, 7, 0.28);
    dg.Insert(5, 1, 0.32);
    dg.Insert(4, 0, 0.38);
    dg.Insert(0, 2, 0.26);
    dg.Insert(3, 7, 0.39);
    dg.Insert(1, 3, 0.29);
    dg.Insert(7, 2, 0.34);
    dg.Insert(6, 2, 0.40);
    dg.Insert(3, 6, 0.52);
    dg.Insert(6, 0, 0.58);
    dg.Insert(6, 4, 0.93);
    dg.Print();
    return 0;
}
