//
//  main.cpp
//  DirectedGraph
//
//  Created by Iqbal Khan on 3/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Digraph.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Digraph l(6);
    l.AddEdge(2,3);
    l.AddEdge(3,1);
    l.AddEdge(4,0);
    l.AddEdge(4,1);
    l.AddEdge(5,0);
    l.AddEdge(5,2);
    l.Print();
    l.RecursiveDFS();
    cout << endl;
    l.PrintEdgeTo();
    return 0;
}
