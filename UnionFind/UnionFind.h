//
//  UnionFind.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/19/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef UnionFind_h
#define UnionFind_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class UF{
private:
    vector<int> connectionsArray;
    vector<int> children;
    int numberOfSites;
    
public:
    UF(int);
    void Union(int,int);
    int FindRoot(int);
    void Unionize(int,int);
    void PrintAllVectors();
};


/// Constructor that takes in the number of sites
/// @param num number of sites
UF::UF(int num) : numberOfSites(num){
    for (int i = 0; i < numberOfSites; i++){
        connectionsArray.push_back(i);
    }
    children.resize(numberOfSites);
    
}

/// Function that'll be called by the client with parent and child
/// @param child integer that is to be designated as child
/// @param parent integer that is to be designated as parent
void UF::Union(int child, int parent){
    int childRoot = FindRoot(child);
    int parentRoot = FindRoot(parent);
    
    //If the two don't already belong to the same component
    if (childRoot != parentRoot){
        if (children[childRoot] == children[parentRoot] || children[childRoot] < children[parentRoot]){
            //Same number of children in both roots, make childRoot the child of parentRoot
            Unionize(parentRoot, childRoot);
        } else {
            Unionize(childRoot, parentRoot);
        }
    } else {
        cout << child << " and " << parent << " are part of the same component with root: " << childRoot << endl;
    }
}

/// Function to find the root for the items being unioned
/// @param r The item being unioned
int UF::FindRoot(int r){
    while(true){
        if (connectionsArray[r] == r)
            break;
        r = connectionsArray[r];
    }
    
    return r;
}

/// Function to actually perform the union operation
/// @param parent integer being designated as parent
/// @param child integer being designated as child
void UF::Unionize(int parent, int child){
    connectionsArray[child] = parent;
    children[parent] += children[child] + 1;
}

/// Function to print vectors
void UF::PrintAllVectors(){
    cout << "Connections Array: " << endl;
    for (auto i : connectionsArray)
        cout << i << " ";
    cout << endl;
    cout << "Children array: " << endl;
    for (auto i : children)
        cout << i << " ";
    cout << endl;
}


#endif /* UnionFind_h */
