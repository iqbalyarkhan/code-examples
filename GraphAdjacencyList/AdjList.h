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
};

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
    for (int i = 1; i < 6; i++){
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
