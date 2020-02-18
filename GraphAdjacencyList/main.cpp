//
//  main.cpp
//  GraphAdjacencyList
//
//  Created by Iqbal Khan on 2/17/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "AdjList.h"
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    AdjList l;
    l.AddEdge(1,4);
    l.AddEdge(4,2);
    l.AddEdge(5,4);
    l.AddEdge(5,2);
    l.AddEdge(5,3);
    l.Print();
    return 0;
}
