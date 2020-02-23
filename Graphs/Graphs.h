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

class AdjMatrix{
private:
    vector<vector<bool>> matrix;
    int vertices = 5;
    void InitAdjMatrix();
    
public:
    AdjMatrix();
    AdjMatrix(int);
    void AddEdge(int,int);
    void Print();
    
};

void AdjMatrix::Print(){
    for (int row = 0; row < vertices; row++){
        for (int col = 0; col < vertices; col++){
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

AdjMatrix::AdjMatrix(int numVertices) : vertices(numVertices){
    InitAdjMatrix();
}

AdjMatrix::AdjMatrix(){
    InitAdjMatrix();
}



void AdjMatrix::InitAdjMatrix(){
    matrix.resize(vertices);
    for (int row = 0; row < vertices; row++){
        matrix[row].resize(vertices);
    }
}

void AdjMatrix::AddEdge(int i, int j){
    matrix[i][j] = true;
    matrix[j][i] = true;
}


#endif /* Graphs_h */
