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
public:
    void Insert(T item);
    void Print();
    Heap();
};

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
