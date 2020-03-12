//
//  Digraph.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef Digraph_h
#define Digraph_h

#include <queue>
#include <vector>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Digraph{
private:
    int vectorSize;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> edgeTo;
    void initializeStructures();
    int numberOfComponents;
    bool hasCycle;
    
public:
    Digraph();
    Digraph(int);
    void AddEdge(int,int);
    void Print();
    void BFS(int);
    void RecursiveDFS();
    void RecursiveDFS(int v);
    void PrintEdgeTo();
    void FindPath(int v, int w);
};

void Digraph::RecursiveDFS(){
    for (int i = 0; i < visited.size(); i++){
        if (!visited[i]){
            RecursiveDFS(i);
        }
    }
}

void Digraph::FindPath(int v, int w){
    /**
     Begin at the w vertex: 5 (push 5 on the stack)
     Check edgeTo[w] = edgeTo[5] = 3. (push 3 on the stack)
     Go to edgeTo[3] = 2 (push 2 on the stack)
     Go to edgeTo[2] = 0 (push 0 on the stack)
     We're now at v vertex: 0
     */
    stack<int> s;
    int end = w;
    while (true){
        s.push(end);
        if (end == v){
            break;
        }
        end = edgeTo[end];
    }
    
    cout << "Path from " << v << " to " << w <<": "<<endl;
    while (!s.empty()) {
        int curr = s.top();
        cout << curr << " ";
         s.pop();
    }
    
    cout << endl;
}

void Digraph::BFS(int v){
    vector<int> marked(vectorSize);
    queue<int> q;
    marked[v] = true;
    q.push(v);
    while (!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int i = 0; i < adjList[curr].size(); i++){
            int neighbor = adjList[curr][i];
            if (!marked[neighbor]){
                edgeTo[neighbor] = curr;
                marked[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}


void Digraph::RecursiveDFS(int v){
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < adjList[v].size(); i++){
        int curr = adjList[v][i];
        if (!visited[curr]){
            edgeTo[curr] = v;
            RecursiveDFS(curr);
        }
    }
}

void Digraph::PrintEdgeTo(){
    for (int i = 0; i < edgeTo.size(); i++){
        cout << "edgeTo[" << i << "]" << " --> " << edgeTo[i] << endl;
    }
}


Digraph::Digraph(int vecSize) : vectorSize(vecSize){
    cout << "Number of vertices was passed as: " << vectorSize << endl;
    initializeStructures();
}
Digraph::Digraph(){
    cout << "Number of vertices defaults to 5..." << endl;
    vectorSize = 5;
    initializeStructures();
}

//Helper function to set sizes for structures
//used for various operations
void Digraph::initializeStructures(){
    adjList.resize(vectorSize);
    visited.resize(vectorSize);
    edgeTo.resize(vectorSize);
    numberOfComponents = 0;
}

void Digraph::Print(){
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

void Digraph::AddEdge(int i, int j){
    adjList[i].push_back(j);
}


#endif /* Digraph_h */
