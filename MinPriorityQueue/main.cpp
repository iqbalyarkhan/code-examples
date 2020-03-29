//
//  main.cpp
//  MinPriorityQueue
//
//  Created by Iqbal Khan on 3/28/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <queue>
#include <functional>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_queue;
    min_queue.push(4);
    min_queue.push(3);
    min_queue.push(2);
    min_queue.push(1);
    min_queue.push(9);
    min_queue.push(13);
    min_queue.push(7);
    
    while (!min_queue.empty()){
        cout << min_queue.top() << " ";
        min_queue.pop();
    }
    cout << endl;
    return 0;
}
