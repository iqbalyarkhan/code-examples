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
    l.AddEdge(0,1);
    l.AddEdge(0,2);
    l.AddEdge(2,1);
    l.AddEdge(2,3);
    l.AddEdge(2,4);
    l.AddEdge(3,5);
    l.AddEdge(4,0);
    l.AddEdge(5,1);
    l.Print();
    l.RecursiveDFS(0);
    cout << endl;
    l.PrintEdgeTo();
    return 0;
}
