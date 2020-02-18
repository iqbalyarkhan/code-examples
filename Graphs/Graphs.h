//
//  Graphs.h
//  Test_UVA
//
//  Created by Iqbal Khan on 2/14/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
// Adjacency Matrix class

#ifndef Graphs_h
#define Graphs_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Graph{
private:
    class Vertex{
    public:
        char item;
        Vertex* next;
    };
    bool** matrix;
    int vertices = 5;
    
    
public:
    Graph();
    void AddEdge(int,int);
    void Print();
    
};

void Graph::Print(){
    for (int row = 0; row < vertices; row++){
        for (int col = 0; col < vertices; col++){
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Graph::Graph(){
    
    matrix = new bool*[vertices];
    for (int row = 0; row < vertices; row++){
        matrix[row] = new bool[vertices];
        for (int col = 0; col < vertices; col++){
            matrix[row][col] = false;
        }
    }
}

void Graph::AddEdge(int i, int j){
    matrix[i][j] = true;
    matrix[j][i] = true;
}


#endif /* Graphs_h */
