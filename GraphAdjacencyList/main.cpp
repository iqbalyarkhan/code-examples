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
    AdjList l(4);
    l.AddEdge(0, 1);
    l.AddEdge(0, 2);
    l.AddEdge(0, 3);
    l.AddEdge(1, 2);
    l.AddEdge(2, 4);
    
//    AdjList l(8);
//    l.AddEdge(0,1);
//    l.AddEdge(0,2);
//    l.AddEdge(0,3);
//    l.AddEdge(0,4);
//    l.AddEdge(1,2);
//    l.AddEdge(1,3);
//    l.AddEdge(1,5);
//    l.AddEdge(2,4);
//    l.AddEdge(2,5);
//    l.AddEdge(4,6);
//    l.AddEdge(4,7);
//    l.AddEdge(6,7);
    l.Print();
    cout << endl;
    l.MST();
//    l.DFS();
    return 0;
}
