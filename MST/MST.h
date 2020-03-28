//
//  MST.h
//  Test_UVA
//
//  Created by Iqbal Khan on 3/23/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef MST_h
#define MST_h

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class MST{
private:
    //From weighted undirected graph
    vector<vector<pair<int,int>>> graph;
    vector<tuple<int,int,int>> minHeap;
    queue<tuple<int,int,int>> actualMST;
    
    //From UnionFind implementation
    vector<int> connectionsArray;
    vector<int> children;
    int numberOfSites;
    
    //From heaps implementation
    void trickleUp(tuple<int,int,int>);
    void trickleDown(tuple<int,int,int>);
    
    
public:
    //From weighted undirected graph
    int GetNumberOfVertices();
    void Insert(int,int, int);
    void Print();
    
    //From UnionFind Implementation
    void Union(int,int);
    int FindRoot(int);
    void Unionize(int,int);
    
    //From heaps implementation
    void HeapInsert(tuple<int,int,int>);
    tuple<int,int,int> HeapGetMin();
    
    //MST
    MST(int v);
    void createMST();
};

tuple<int,int,int> MST::HeapGetMin(){
    tuple<int,int,int> minElement = minHeap[0];
    int replacement = int(minHeap.size() - 1);
    minHeap[0] = minHeap[replacement];
    minHeap.erase(minHeap.end() - 1);
    if (int(minHeap.size()) != 1)
        trickleDown(minHeap[0]);
    return minElement;
}

void MST::createMST(){
    int count = 0;
    int weight = 0;
    while (count != (numberOfSites - 1)){
        tuple<int,int,int> minElement = HeapGetMin();
        int child = get<0>(minElement);
        int parent = get<1>(minElement);
        if (FindRoot(child) != FindRoot(parent)){
            weight += get<2>(minElement);
            cout << child << " - " << parent << " " << endl;
            Union(child, parent);
            count++;
        } else {
            cout << child << " - " << parent << " would cause a cycle" << endl;
        }
    }
    cout << "And min weight is: " << weight << endl;
    cout << endl;
}

void MST::trickleUp(tuple<int,int,int> item){
    //Trickle up will always start at
    //the last index and will work its
    //way up the array
    int curr = int(minHeap.size() - 1);
    while (curr != 0){
        //Get parent index
        int parent = ((curr - 1) / 2);
        if (get<2>(minHeap[curr]) < get<2>(minHeap[parent]) ){
            //Newly added node's weight < parent's weight
            //Move up the newly added node and re-check
            tuple<int,int,int> temp = minHeap[parent];
            minHeap[parent] = minHeap[curr];
            minHeap[curr] = temp;
            curr = parent;
        } else {
            //Parent was not > child,
            //we're done
            break;
        }
    }
}

void MST::trickleDown(tuple<int,int,int> item){
    //Trickle down will always begin from root,
    //so we'll always assume that the index is 0
    //for the item to be trickled down.
    int currIndex = 0;
    int arraySize = int(minHeap.size()) - 1;
    while (true){
        int leftChildIndex = (currIndex * 2) + 1;
        int rightChildIndex = (currIndex * 2) + 2;
        if (leftChildIndex <= arraySize && rightChildIndex <= arraySize){
            //We have both, a left and a right child
            if (get<2>(minHeap[leftChildIndex]) < get<2>(minHeap[currIndex]) && get<2>(minHeap[leftChildIndex]) < get<2>(minHeap[rightChildIndex])){
                //Left child is less than curr AND is also less than right child
                //Swap curr with left child
                tuple<int,int,int> temp = minHeap[leftChildIndex];
                minHeap[leftChildIndex] = minHeap[currIndex];
                minHeap[currIndex] = temp;
                currIndex = leftChildIndex;
            } else if (get<2>(minHeap[rightChildIndex]) < get<2>(minHeap[currIndex]) && get<2>(minHeap[rightChildIndex]) < get<2>(minHeap[leftChildIndex])){
                //Right child is less than curr AND is also less than left child
                //Swap curr with right child
                tuple<int,int,int> temp = minHeap[rightChildIndex];
                minHeap[rightChildIndex] = minHeap[currIndex];
                minHeap[currIndex] = temp;
                currIndex = rightChildIndex;
            } else {
                //Left and right child have the same weight, just pick one at random
                tuple<int,int,int> temp = minHeap[rightChildIndex];
                minHeap[rightChildIndex] = minHeap[currIndex];
                minHeap[currIndex] = temp;
                currIndex = rightChildIndex;
            }
        } else if (leftChildIndex <= arraySize && get<2>(minHeap[leftChildIndex]) < get<2>(minHeap[currIndex])){
            //Only left child exists and this left child
            //is less than the element we're swapping
            tuple<int,int,int> temp = minHeap[leftChildIndex];
            minHeap[leftChildIndex] = minHeap[currIndex];
            minHeap[currIndex] = temp;
            currIndex = leftChildIndex;
        } else if (rightChildIndex <= arraySize && get<2>(minHeap[rightChildIndex]) < get<2>(minHeap[currIndex])){
            //Only right child exists and this right child
            //is less than the element we're swapping
            tuple<int,int,int> temp = minHeap[rightChildIndex];
            minHeap[rightChildIndex] = minHeap[currIndex];
            minHeap[currIndex] = temp;
            currIndex = rightChildIndex;
        } else {
            return;
        }
        
    }
    
}

MST::MST(int v) : numberOfSites(v){
    for (int i = 0; i < numberOfSites; i++)
        connectionsArray.push_back(i);
    children.resize(numberOfSites);
    graph.resize(numberOfSites);
}

void MST::Insert(int from, int to, int weight){
    //Add edges to graph representation
//    pair<int,int> edge1(from, weight);
//    pair<int,int> edge2(to,weight);
//    graph[from].push_back(edge2);
//    graph[to].push_back(edge1);
    //Add edges to our min heap
    tuple<int,int,int> newItemForHeap(from,to,weight);
    HeapInsert(newItemForHeap);
}

void MST::Unionize(int parent, int child){
    connectionsArray[child] = parent;
    children[parent] += children[child] + 1;
}

int MST::FindRoot(int r){
    while(true){
        if (connectionsArray[r] == r)
            break;
        r = connectionsArray[r];
    }
    
    return r;
}

void MST::Union(int child, int parent){
    int childRoot = FindRoot(child);
    int parentRoot = FindRoot(parent);
    if (children[childRoot] == children[parentRoot] || children[childRoot] < children[parentRoot]){
        //Same number of children in both roots, make childRoot the child of parentRoot
        Unionize(parentRoot, childRoot);
    } else {
        Unionize(childRoot, parentRoot);
    }
}

void MST::HeapInsert(tuple<int, int, int>curr){
    //Adding to end of vector
    minHeap.push_back(curr);
    trickleUp(curr);
}

void MST::Print(){
    cout << endl;
    for (int i = 0; i < graph.size(); i++){
        cout << i;
        for (int j = 0; j < graph[i].size(); j++){
            cout << " -> ";
            cout << "(" << graph[i][j].first << ", ";
            cout << graph[i][j].second << ")";
        }
        cout << endl;
    }
    cout << endl;
}

#endif /* MST_h */
