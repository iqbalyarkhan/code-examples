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
    
    Graph g;
    g.Print();
    g.AddEdge(2, 3);
    g.AddEdge(1, 4);
    g.AddEdge(0, 1);
    g.Print();
    
    return 0;
}
