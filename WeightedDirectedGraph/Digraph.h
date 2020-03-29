//
//  Digraph.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/29/20.
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
    vector<vector<pair<int,double>>> adjList;
    vector<bool> visited;
    vector<int> edgeTo;
    queue<int> pre;
    queue<int> post;
    stack<int> reversePost;
    
    void initializeStructures();
    int numberOfComponents;
    
public:
    Digraph(int);
    void Insert(int,int,double);
    void Print();
    void BFS(int);
    void RecursiveDFS();
    void RecursiveDFS(int v);
    void PrintEdgeTo();
    void FindPath(int v, int w);
    void PrintOrder();
};

//void Digraph::PrintOrder(){
//    cout << "Pre: " << endl;
//    while (!pre.empty()){
//        cout << pre.front() << " ";
//        pre.pop();
//    }
//    cout << endl;
//    cout << "Post: " << endl;
//    while (!post.empty()){
//        cout << post.front() << " ";
//        post.pop();
//    }
//    cout << endl;
//    cout << "Reverse Post: " << endl;
//    while (!reversePost.empty()){
//        cout << reversePost.top() << " ";
//        reversePost.pop();
//    }
//    cout << endl;
//}
//
//void Digraph::RecursiveDFS(){
//    for (int i = 0; i < visited.size(); i++){
//        if (!visited[i]){
//            RecursiveDFS(i);
//        }
//    }
//}
//
//void Digraph::RecursiveDFS(int v){
//    visited[v] = true;
//    pre.push(v);
//    for (int i = 0; i < adjList[v].size(); i++){
//        int curr = adjList[v][i];
//        if (!visited[curr]){
//            edgeTo[curr] = v;
//            RecursiveDFS(curr);
//        }
//    }
//    post.push(v);
//    reversePost.push(v);
//}
//
//void Digraph::FindPath(int v, int w){
//    /**
//     Begin at the w vertex: 5 (push 5 on the stack)
//     Check edgeTo[w] = edgeTo[5] = 3. (push 3 on the stack)
//     Go to edgeTo[3] = 2 (push 2 on the stack)
//     Go to edgeTo[2] = 0 (push 0 on the stack)
//     We're now at v vertex: 0
//     */
//    stack<int> s;
//    int end = w;
//    while (true){
//        s.push(end);
//        if (end == v){
//            break;
//        }
//        end = edgeTo[end];
//    }
//
//    cout << "Path from " << v << " to " << w <<": "<<endl;
//    while (!s.empty()) {
//        int curr = s.top();
//        cout << curr << " ";
//         s.pop();
//    }
//
//    cout << endl;
//}
//
//void Digraph::BFS(int v){
//    vector<int> marked(vectorSize);
//    queue<int> q;
//    marked[v] = true;
//    q.push(v);
//    while (!q.empty()){
//        int curr = q.front();
//        cout << curr << " ";
//        q.pop();
//        for (int i = 0; i < adjList[curr].size(); i++){
//            int neighbor = adjList[curr][i];
//            if (!marked[neighbor]){
//                edgeTo[neighbor] = curr;
//                marked[neighbor] = true;
//                q.push(neighbor);
//            }
//        }
//    }
//    cout << endl;
//}
//
//void Digraph::PrintEdgeTo(){
//    for (int i = 0; i < edgeTo.size(); i++){
//        cout << "edgeTo[" << i << "]" << " --> " << edgeTo[i] << endl;
//    }
//}
//
//
Digraph::Digraph(int vecSize) : vectorSize(vecSize){
    cout << "Number of vertices was passed as: " << vectorSize << endl;
    initializeStructures();
}
//
//Helper function to set sizes for structures
//used for various operations
void Digraph::initializeStructures(){
    adjList.resize(vectorSize);
    visited.resize(vectorSize);
    edgeTo.resize(vectorSize);
    numberOfComponents = 0;
}
//
void Digraph::Print(){
    cout << endl;
    for (int i = 0; i < adjList.size(); i++){
        cout << i;
        for (int j = 0; j < adjList[i].size(); j++){
            cout << " -> ";
            cout << "(" << adjList[i][j].first << ", ";
            cout << adjList[i][j].second << ")";
        }
        cout << endl;
    }
    cout << endl;
}

void Digraph::Insert(int from, int to, double weight){
    pair<int,double> edge(to,weight);
    adjList[from].push_back(edge);
}


#endif /* Digraph_h */
