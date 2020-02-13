//
//  main.cpp
//  Heap
//
//  Created by Iqbal Khan on 2/10/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Heap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Heap<int> h;
    h.Insert(40);
    h.Insert(30);
    h.Insert(20);
    h.Insert(10);
    h.Insert(90);
    h.Insert(25);
    while (true){
        cout << "Get max? " << endl;
        char ch;
        cin >> ch;
        if (ch == 'n')
            break;
        cout << "Max is: " <<h.GetMax() << endl;
        cout << "New arr after max: " << endl;
        h.Print();
    }
    return 0;
}
