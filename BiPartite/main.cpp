//
//  main.cpp
//  BiPartite
//
//  Created by Iqbal Khan on 3/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "AdjList.h"
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    AdjList l(7);
    l.AddEdge(0,1);
    l.AddEdge(0,2);
    l.AddEdge(2,3);
    l.AddEdge(2,4);
    l.AddEdge(4,6);
    l.AddEdge(4,5);
    l.AddEdge(5,6);
    l.IsBiPartite();
    return 0;
}
