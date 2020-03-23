//
//  main.cpp
//  Weighted Undirected Graph
//
//  Created by Iqbal Khan on 3/22/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string>
#include <utility>

#include "WeightedUndirectedGraph.h"

int main(int argc, const char * argv[]) {
    WUG wug(5);
    wug.Insert(0, 1, 3);
    wug.Insert(0, 2, 5);
    wug.Insert(1, 2, 2);
    wug.Insert(2, 3, 4);
    wug.Insert(2, 4, 4);
    wug.Insert(3, 4, 7);
    wug.Print();
    return 0;
}
