//
//  AdjList.h
//  Test_UVA
//
//  Created by Iqbal Khan on 2/17/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef AdjList_h
#define AdjList_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class AdjList{
private:
    int vectorSize;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<bool> colors;
    vector<int> edgeTo;
    void initializeStructures();
    
public:
    AdjList();
    AdjList(int);
    void AddEdge(int,int);
    void Print();
    void IsBiPartite();
    void DFSBiPartite(int v);
};

void AdjList::IsBiPartite(){
    for (int i = 0; i < vectorSize; i++){
        if (!visited[i])
            DFSBiPartite(0);
    }
}

void AdjList::DFSBiPartite(int v){
    visited[v] = true;
    cout << v << "'s color " << colors[v] << endl;
    for (int i = 0; i < adjList[v].size(); i++){
        int neighbor = adjList[v][i];
        if (!visited[neighbor]){
            colors[neighbor] = !(colors[v]);
            DFSBiPartite(neighbor);
        } else if (visited[neighbor]){
            if (colors[neighbor] == colors[v]){
                cout << "Not bi partite because " << neighbor << " and " << v << " have the same color" << endl;
            }
        }
    }
}

AdjList::AdjList(int vecSize) : vectorSize(vecSize){
    cout << "Number of vertices was passed as: " << vectorSize << endl;
    initializeStructures();
}
AdjList::AdjList(){
    cout << "Number of vertices defaults to 5..." << endl;
    vectorSize = 5;
    initializeStructures();
}

//Helper function to set sizes for structures
//used for various operations
void AdjList::initializeStructures(){
    adjList.resize(vectorSize);
    visited.resize(vectorSize);
    edgeTo.resize(vectorSize);
    colors.resize(vectorSize);
}

void AdjList::Print(){
    for (int i = 0; i < vectorSize; i++){
        cout << i;
        for (auto j : adjList[i]){
            cout << " -> ";
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
}

void AdjList::AddEdge(int i, int j){
    adjList[i].push_back(j);
    adjList[j].push_back(i);
}

#endif /* AdjList_h */
