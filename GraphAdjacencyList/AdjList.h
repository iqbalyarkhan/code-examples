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
    //Adding one more to the num
    //since vectors start at 0 and
    //we want 1-5. So 0 will remain
    //empty
    int vectorSize;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> edgeTo;
    void initializeStructures();
    int numberOfComponents;
    bool hasCycle;
    
public:
    AdjList();
    AdjList(int);
    void AddEdge(int,int);
    void Print();
    void AddVertex(int);
    void DeleteVertex(int);
    void DFS(int);
    void BFS(int);
    void RecursiveDFS(int v);
    void MST();
    void PrintEdgeTo();
    void FindPath(int v, int w);
    void FindConnectedComponents();
    bool CyclePresent();
    void CycleDFS(int,int);
};

bool AdjList::CyclePresent(){
    //https://www.youtube.com/watch?v=eCG3T1m7rFY
    //Does the graph have a cycle? https://www.youtube.com/watch?v=L0DcePeWHnM
    CycleDFS(0, -1);
    if (hasCycle)
        cout << "There is a cycle!" << endl;
    return hasCycle;
}

void AdjList::CycleDFS(int v, int parent){
    cout << "v is: " << v << " and parent is: " << parent << endl;
    visited[v] = true;
    for (int i = 0; i < adjList[v].size(); i++){
        int neighbor = adjList[v][i];
        if (!visited[neighbor]){
            CycleDFS(neighbor, v);
        } else {
            if (neighbor != parent){
                hasCycle = true;
            }
        }
    }
}

void AdjList::FindConnectedComponents(){
    //Initializing the components array:
    vector<int> components(vectorSize, -1);
    //clear out the visited array and set size
    //to number of vertices
    visited.clear();
    visited.resize(vectorSize);
    int curr = 0;
    int componentNumber = 0;
    while (true){
        componentNumber++;
        DFS(curr);
        for (int i = 0; i < visited.size(); i++){
            if (visited[i]){
                components[i] = componentNumber;
            }
        }
        
        curr = -1;
        for (int i = 0; i < components.size(); i++){
            if(components[i] == -1){
                curr = i;
                break;
            }
        }
        if (curr == -1){
            break;
        }
        
        visited.clear();
        visited.resize(vectorSize);
    }
    cout << "Components array: " << endl;
    for (auto j : components){
        cout << j << " ";
    }
    cout << endl;
}

void AdjList::FindPath(int v, int w){
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

void AdjList::BFS(int v){
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


void AdjList::RecursiveDFS(int v){
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

void AdjList::PrintEdgeTo(){
    for (int i = 0; i < edgeTo.size(); i++){
        cout << "edgeTo[" << i << "]" << " --> " << edgeTo[i] << endl;
    }
}


//Function that takes in the additional
//number of vertices that you want
void AdjList::AddVertex(int num){
    vectorSize+= num;
    adjList.resize(vectorSize);
}

//Function to delete vertex passed
void AdjList::DeleteVertex(int v){
    if (v > vectorSize)
        return;
    //Empties vertex v's adjacency list
    adjList[v].clear();
    //Looks through other adjacency lists and removes
    //v from those lists.
    for (int i = 0; i < vectorSize; i++){
        auto itr = adjList[i].begin();
        while (itr != adjList[i].end()){
            if (*itr == v){
                itr = adjList[i].erase(itr);
            } else {
                itr++;
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
    numberOfComponents = 0;
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

void AdjList::MST(){
    //Need an array to keep track of visited
    //nodes. All values will be initialized to 0
    vector<bool> visited(vectorSize);
    stack<int> elemStack;
    int curr = 0;
    elemStack.push(curr);
    while (elemStack.size() != 0){
        if (!visited[curr]){
            cout << curr << " ";
            visited[curr] = true;
        }
        
        for (int j = 0; j < adjList[curr].size(); j++){
            int neighbor = adjList[curr][j];
            if (!visited[neighbor]){
                elemStack.push(neighbor);
            }
        }
        
        curr = elemStack.top();
        elemStack.pop();
    }
}

void AdjList::DFS(int curr){
    //Need an array to keep track of visited
    //nodes. All values will be initialized to 0
//    vector<bool> visited(vectorSize);
//    stack<int> elemStack;
    queue<int> elemStack;
    elemStack.push(curr);
    while (elemStack.size() != 0){
        if (!visited[curr]){
            cout << curr << " ";
            visited[curr] = true;
        }
        
        for (int j = 0; j < adjList[curr].size(); j++){
            int neighbor = adjList[curr][j];
            if (!visited[neighbor]){
                elemStack.push(neighbor);
            }
        }
        
        curr = elemStack.front();
        elemStack.pop();
    }
}


#endif /* AdjList_h */
