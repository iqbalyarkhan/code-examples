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
#include <utility>

using namespace std;

class MST{
private:
    //From weighted undirected graph
    vector<vector<pair<int,int>>> graph;
    
    //From UnionFind implementation
    vector<int> connectionsArray;
    vector<int> children;
    int numberOfSites;
    
    //From heaps implementation
    vector<int> heapArr;
    void trickleUp(int item);
    void trickleDown(int item);
    
    
public:
    //From weighted undirected graph
    int GetNumberOfVertices();
    void Insert(int,int, int);
    void Print();
    
    //From UnionFind Implementation
    void Union(int,int);
    int FindRoot(int);
    void Unionize(int,int);
    
    //From heaps implementation
    void Insert(int item);
    int GetMin();
    
    //MST
    MST(int v);
};

MST::MST(int v) : numberOfSites(v){
    for (int i = 0; i < numberOfSites; i++)
        connectionsArray.push_back(i);
    children.resize(numberOfSites);
    graph.resize(numberOfSites);
}

void MST::Insert(int from, int to, int weight){
    pair<int,int> edge1(from, weight);
    pair<int,int> edge2(to,weight);
    graph[from].push_back(edge2);
    graph[to].push_back(edge1);
}

void MST::Print(){
    cout << endl;
    for (int i = 0; i < graph.size(); i++){
        cout << i;
        for (int j = 0; j < graph[i].size(); j++){
            cout << " -> ";
            cout << "(" << graph[i][j].first << ", ";
            cout << graph[i][j].second << ")";
        }
        cout << endl;
    }
    cout << endl;
}

#endif /* MST_h */
