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
    int vectorSize = 6;
    vector<vector<int>> adjList;
    
public:
    AdjList();
    AdjList(int);
    void AddEdge(int,int);
    void Print();
    void AddVertex(int);
    void DeleteVertex(int);
    void DFS();
    void MST();
};

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

AdjList::AdjList(int vecSize) : vectorSize(vecSize + 1){
    cout << "Number of vertices was passed as: " << vectorSize << endl;
    adjList.resize(vectorSize);
}
AdjList::AdjList(){
    cout << "Number of vertices defaults to 5..." << endl;
    vectorSize = 6;
    adjList.resize(vectorSize);
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

void AdjList::DFS(){
    //Need an array to keep track of visited
    //nodes. All values will be initialized to 0
    vector<bool> visited(vectorSize);
//    stack<int> elemStack;
    queue<int> elemStack;
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
        
        curr = elemStack.front();
        elemStack.pop();
    }
}


#endif /* AdjList_h */
