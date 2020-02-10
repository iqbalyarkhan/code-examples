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
    vector<T> HeapArray;
    int size;
public:
    Heap();
};

template <typename T>
Heap<T>::Heap(){
    size = 0;
}

#endif /* Heap_h */
