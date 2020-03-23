//
//  WeightedUndirectedGraph.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/22/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef WeightedUndirectedGraph_h
#define WeightedUndirectedGraph_h

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string>
#include <utility>

using namespace std;

class WUG{
  
private:
    int numberOfVertices;
    vector<vector<pair<int,int>>> graph;
    
public:
    WUG(int v);
    int GetNumberOfVertices();
    void Insert(int,int, int);
    void Print();
};


/// Function to insert an edge to our adjacency list
/// @param from edge from
/// @param to edge to
/// @param weight the weight of the edge
void WUG::Insert(int from, int to, int weight){
    //Create two pairs, one for each vertex.
    pair<int,int> edge1(from, weight);
    pair<int,int> edge2(to, weight);
    //Push each pair to relevant index
    graph[from].push_back(edge2);
    graph[to].push_back(edge1);
}

void WUG::Print(){
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

/// Constructor to initialize our vector of vector of pairs
/// @param v the number of vertices
WUG::WUG(int v) : numberOfVertices(v){
    graph.resize(numberOfVertices);
}

int WUG::GetNumberOfVertices(){
    return numberOfVertices;
}

#endif /* WeightedUndirectedGraph_h */
