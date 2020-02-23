//
//  main.cpp
//  Graphs
//
//  Created by Iqbal Khan on 2/14/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Graphs.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    AdjMatrix g(6);
    g.Print();
    g.AddEdge(1, 4);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(3, 5);
    g.AddEdge(4, 5);
    g.Print();
    
    return 0;
}
