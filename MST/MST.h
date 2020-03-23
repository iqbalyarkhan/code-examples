//
//  MST.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/23/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef MST_h
#define MST_h

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include 

using namespace std;

class MST{
private:
    //From UnionFind implementation
    vector<int> connectionsArray;
    vector<int> children;
    int numberOfSites;
    
    //From heaps implementation
    vector<int> heapArr;
    void trickleUp(int item);
    void trickleDown(int item);
    
    
public:
    //From UnionFind Implementation
    void Union(int,int);
    int FindRoot(int);
    void Unionize(int,int);
    
    //From heaps implementation
    void Insert(int item);
    int GetMin();
    
};

#endif /* MST_h */
