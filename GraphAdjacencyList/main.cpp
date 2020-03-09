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
//    AdjList l(11);
//    l.AddEdge(0, 2);
//    l.AddEdge(0, 1);
//    l.AddEdge(0, 3);
//    l.AddEdge(4, 7);
//    l.AddEdge(5, 7);
//    l.AddEdge(5, 6);
//    l.AddEdge(6, 7);
//    l.AddEdge(8, 10);
//    l.AddEdge(9, 10);
//    l.Print();
//    cout << endl;
//    l.BFS(0);
//    cout << endl;
//    l.PrintEdgeTo();
//    l.FindConnectedComponents();
//    l.DFS();
//    cout << "Recursive DFS" << endl;
//    l.RecursiveDFS(0);
//    cout << endl;
//    cout << "BFS: " << endl;
//    l.BFS(0);
//    cout << "Edge to: " << endl;
//    l.PrintEdgeTo();
//    l.FindPath(0, 5);
//    cout <<"Printing edge to: " << endl;
//    l.PrintEdgeTo();
//    cout << "Find path: " << endl;
//    l.FindPath(2, 5);
//    cout << endl;
//    l.FindPath(0,4);
    AdjList l(7);
    l.AddEdge(0,1);
    l.AddEdge(0,2);
    l.AddEdge(2,3);
    l.AddEdge(2,4);
    l.AddEdge(4,5);
    l.AddEdge(4,6);
    l.AddEdge(5,6);
    l.Print();
//    l.BFS(0);
    cout << endl;
    l.CyclePresent();
//    l.DFS(0);
//    l.PrintEdgeTo();
//    l.AddVertex(3);
//    cout << "After adding 3 more vertices: " << endl;
//    l.Print();
//    l.DeleteVertex(2);
//    cout << "After deleting 2" << endl;
//    l.Print();
//    cout << endl;
//    l.MST();
//    l.DFS();
    return 0;
}
