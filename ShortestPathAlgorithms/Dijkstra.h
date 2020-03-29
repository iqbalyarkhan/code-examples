//
//  Dijkstra.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/29/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef Dijkstra_h
#define Dijkstra_h

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string>
#include <utility>
#include <limits>
#include <stack>


using namespace std;

class Digraph{
  
private:
    int numberOfVertices;
    vector<vector<pair<int,int>>> adjList;
    vector<int> dist;
    vector<int> edge;
    vector<pair<int,int>> sortedEdges;
    /**
     Method name: Relax
     Description: Function to relax edges ie update dist and edge arrays
     Parameters: s - the source vertex
     */
    void Relax(int);
    
    /**
     Method name: AddToSortedEdges
     Description: Function to add vertex and weight to sortedEdges vector
     Parameters: s - vertex, weight - the weight
     */
    void AddToSortedEdges(int s, int weight);
    
    /**
     Method name: PrintAllSingleSourceShortestPaths
     Description: Function to print all paths from source
     */
    void PrintAllSingleSourceShortestPaths();
    
public:
    /**
       * Method name: PrintDPrintArraysist
       * Description: Method to print the edge and dist arrays
       * Parameters: None
       */
    void PrintArrays();
    
    /**
      * Method name: Digraph
      * Description: Constructor
      * Parameters: Takes in number of vertices
      */
    Digraph(int v);
    
    /**
      * Method name: GetNumberOfVertices
      * Description: Returns number of vertices in the graph
      * Parameters: none
      */
    int GetNumberOfVertices();
    
    /**
      * Method name: Insert
      * Description: Inserts a new pair to adjList with weight
      * Parameters: from edge, to edge, weight of edge
      */
    void Insert(int,int, int);
    
    /**
      * Method name: Print
      * Description: Prints graph
      * Parameters: none
      */
    void Print();
    
    /**
     Method name: SPADijkstra
     Description: Client function to find single source shortest paths from s
     Parameters: s - the source vertex
     */
    void SPADijkstra(int s);
    
};

void Digraph::PrintAllSingleSourceShortestPaths(){
    for (int i = 0; i <= numberOfVertices - 1; i++){
        cout << "Path from 0 to " << i << ": ";
        int curr = i;
        stack<int> s;
        s.push(curr);
        while (curr != 0){
            curr = edge[curr];
            s.push(curr);
        }
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << " has weight: " << dist[i];
        cout << endl;
        
    }
}

void Digraph::PrintArrays(){
    cout << "Index" << " " << "dist[]" << " " << "edge[]" << endl;
    for (int i = 0; i < dist.size(); i++){
        cout << i << " " << dist[i] << " " <<edge[i]<< endl;
    }
}

void Digraph::AddToSortedEdges(int s, int weight){
    sortedEdges.push_back(make_pair(weight, s));
    sort(sortedEdges.begin(), sortedEdges.end());
}

void Digraph::SPADijkstra(int s){
    edge.resize(numberOfVertices);
    for (int i = 0; i < numberOfVertices; i++){
        //Setting the distance to infinity for each vertex initially
        int a = numeric_limits<int>::max();
        dist.push_back(a);
    }
    
    //Changing the source's distance to 0.0
    dist[s] = 0.0;
    AddToSortedEdges(0, 0);
    while (!sortedEdges.empty()){
        int s = sortedEdges[0].second;
        sortedEdges.erase(sortedEdges.begin());
        Relax(s);
    }
    PrintAllSingleSourceShortestPaths();
}

void Digraph::Relax(int s){
    //Get all adjacent vertices to passed in vertex
    for (int i = 0; i < adjList[s].size(); i++){
        //w is the adjacent vertex
        int w = adjList[s][i].first;
        //weight is the weight of that edge
        int weight = adjList[s][i].second + dist[s];
        //If this weight is less than what dist stores
        if (dist[w] > weight){
            //update the weights for that edge and the edge array
            dist[w] = weight;
            edge[w] = s;
            //Next update the edge weights in the sortedEdges array
            bool found = false;
            for (int i = 0; i < sortedEdges.size(); i++){
                if (sortedEdges[i].second == w){
                    sortedEdges[i].first = weight;
                    found = true;
                    sort(sortedEdges.begin(),sortedEdges.end());
                    break;
                }
            }
            
            if (!found){
                AddToSortedEdges(w, weight);
            }
        }
    }
}

void Digraph::Insert(int from, int to, int weight){
    //Create pair for vertex.
    pair<int,double> edge(to, weight);
    //Push the edge on from's adjacency list
    adjList[from].push_back(edge);
}

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

/// Constructor to initialize our vector of vector of pairs
/// @param v the number of vertices
Digraph::Digraph(int v) : numberOfVertices(v){
    adjList.resize(numberOfVertices);
}

int Digraph::GetNumberOfVertices(){
    return numberOfVertices;
}


#endif /* Dijkstra_h */
