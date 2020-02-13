//
//  Heap.h
//  Test_UVA
//
//  Created by Iqbal Khan on 2/10/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef Heap_h
#define Heap_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Heap{
private:
    vector<T> heapArr;
    void trickleUp(T item);
    void trickleDown(T item);
public:
    void Insert(T item);
    T GetMax();
    void Print();
    Heap();
};

template <typename T>
void Heap<T>::Print(){
    for (auto it : heapArr)
        cout << it << " ";
    cout << endl;
}

template <typename T>
void Heap<T>::trickleDown(T item){
    //Trickle down will always begin from root,
    //so we'll always assume that the index is 0
    //for the item to be trickled down.
    int currIndex = 0;
    int arraySize = int(heapArr.size()) - 1;
    while (true){
        T leftChildIndex = (currIndex * 2) + 1;
        T rightChildIndex = (currIndex * 2) + 2;
        if (leftChildIndex <= arraySize && rightChildIndex <= arraySize){
            //We have both, a left and a right child
            if (heapArr[leftChildIndex] > heapArr[currIndex] && heapArr[leftChildIndex] > heapArr[rightChildIndex]){
                //Left child is greater than curr AND is also greater than right child
                //Swap curr with left child
                T temp = heapArr[leftChildIndex];
                heapArr[leftChildIndex] = heapArr[currIndex];
                heapArr[currIndex] = temp;
                currIndex = leftChildIndex;
            } else if (heapArr[rightChildIndex] > heapArr[currIndex] && heapArr[rightChildIndex] > heapArr[leftChildIndex]){
                //Right child is greater than curr AND is also greater than left child
                //Swap curr with right child
                T temp = heapArr[rightChildIndex];
                heapArr[rightChildIndex] = heapArr[currIndex];
                heapArr[currIndex] = temp;
                currIndex = rightChildIndex;
            }
        } else if (leftChildIndex <= arraySize && heapArr[leftChildIndex] > heapArr[currIndex]){
            //Only left child exists and this left child
            //is greater than the element we're swapping
            T temp = heapArr[leftChildIndex];
            heapArr[leftChildIndex] = heapArr[currIndex];
            heapArr[currIndex] = temp;
            currIndex = leftChildIndex;
        } else if (rightChildIndex <= arraySize && heapArr[rightChildIndex] > heapArr[currIndex]){
            //Only right child exists and this right child
            //is greater than the element we're swapping
            T temp = heapArr[rightChildIndex];
            heapArr[rightChildIndex] = heapArr[currIndex];
            heapArr[currIndex] = temp;
            currIndex = rightChildIndex;
        } else {
            //We've found the correct spot,
            //we can exit
            return;
        }
        
    }
    
}

template <typename T>
T Heap<T>::GetMax(){
    T max = heapArr[0];
    int replacement = int(heapArr.size() - 1);
    heapArr[0] = heapArr[replacement];
    heapArr.erase(heapArr.end() - 1);
    if (int(heapArr.size()) != 1)
        trickleDown(heapArr[0]);
    return max;
}

template <typename T>
void Heap<T>::trickleUp(T item){
    //Trickle up will always start at
    //the last index and will work its
    //way up the array
    int curr = int(heapArr.size() - 1);
    while (curr != 0){
        //Get parent index
        int parent = ((curr - 1) / 2);
        if (heapArr[parent] < heapArr[curr]){
            //Parent was less than newly added node
            //Move up the newly added node and re-check
            T temp = heapArr[parent];
            heapArr[parent] = heapArr[curr];
            heapArr[curr] = temp;
            curr = parent;
        } else {
            //Parent was not > child,
            //we're done
            break;
        }
    }
    
    cout << "Heap after inserting " << item << endl;
    
    for (auto item : heapArr){
        cout << item << " ";
    }
    
    cout << endl;
    
}

template <typename T>
void Heap<T>::Insert(T item){
    if (int(heapArr.size()) == 0){
        //Empty array, just push
        //new item
        heapArr.push_back(item);
    } else{
        //Array not empty, push to end
        //and call helper function
        heapArr.push_back(item);
        trickleUp(item);
    }
}

template <typename T>
Heap<T>::Heap(){
}

#endif /* Heap_h */
