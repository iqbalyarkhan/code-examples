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
    
public:
    
    void PrintDist();
    
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

void Digraph::PrintDist(){
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
}

void Digraph::Relax(int s){
    for (int i = 0; i < adjList[s].size(); i++){
        int w = adjList[s][i].first;
        int weight = adjList[s][i].second + dist[s];
        if (dist[w] > weight){
            dist[w] = weight;
            edge[w] = s;
            
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

/// Function to insert an edge to our adjacency list
/// @param from edge from
/// @param to edge to
/// @param weight the weight of the edge
/// @example 0,2, 0.26 : 0-->2 has weight 0.26, so add 2,0.26 to 0's adj list
void Digraph::Insert(int from, int to, int weight){
    //Create two pairs, one for each vertex.
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
