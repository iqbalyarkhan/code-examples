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
    Digraph l(8);
    l.AddEdge(0,3);
    l.AddEdge(0,4);
    l.AddEdge(1,4);
    l.AddEdge(2,5);
    l.AddEdge(3,6);
    l.AddEdge(4,6);
    l.AddEdge(5,7);
    l.AddEdge(6,7);
    l.Print();
    l.RecursiveDFS();
    cout << endl;
    l.PrintEdgeTo();
    
    /**
         Digraph l(13);
         l.AddEdge(0,1);
         l.AddEdge(0,5);
         l.AddEdge(0,6);
         l.AddEdge(2,0);
         l.AddEdge(2,3);
         l.AddEdge(3,5);
         l.AddEdge(5,4);
         l.AddEdge(6,4);
         l.AddEdge(6,9);
         l.AddEdge(7,6);
         l.AddEdge(8,7);
         l.AddEdge(9,10);
         l.AddEdge(9,11);
         l.AddEdge(9,12);
         l.AddEdge(11,12);
         l.Print();
         cout << endl;
         l.RecursiveDFS();
         cout << endl;
     //    l.PrintEdgeTo();
         return 0;
     
     */
    
    return 0;
}
