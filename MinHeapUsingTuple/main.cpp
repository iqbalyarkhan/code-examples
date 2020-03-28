//
//  main.cpp
//  MinHeapUsingTuple
//
//  Created by Iqbal Khan on 3/27/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//
#include <iostream>
#include <tuple>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// comparator function to make min heap
struct minComparator{
  bool operator()(const tuple<int, int, int>& a,
  const tuple<int, int, int>& b) const{
      cout << get<2>(a) << " and " << get<2>(b) << endl;
    return (get<2>(a) < get<2>(b));
  }
};

int main(int argc, const char * argv[]) {
    vector<tuple<int,int,int>> minHeap;
    auto t1 = make_tuple(2,3,4);
    auto t2 = make_tuple(0,1,1);
    auto t3 = make_tuple(-1,-1,3);
    auto t4 = make_tuple(1,2,5);
    minHeap.push_back(t1);
    minHeap.push_back(t2);
    minHeap.push_back(t3);
    minHeap.push_back(t4);
    make_heap(minHeap.begin(), minHeap.end(),minComparator());
    cout << "after make_heap: " << endl;
    for (int i = 0; i < minHeap.size(); i++){
        tuple<int,int,int> curr = minHeap[i];
        cout << get<0>(curr) << "," << get<1>(curr) << "," << get<2>(curr) << endl;
    }
    cout << endl;
    
    return 0;
}
