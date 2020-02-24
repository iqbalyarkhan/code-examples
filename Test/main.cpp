//
//  main.cpp
//  Test
//
//  Created by Iqbal Khan on 2/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Test.h"

int main(int argc, const char * argv[]) {
    vector<int>* arr[3];
    arr[0] = new vector<int>;
    arr[1] = new vector<int>;
    arr[2] = new vector<int>;
    cout << "hello world!" << endl;
    cout << "Yo yo honey singh!" << endl;
    arr[0]->push_back(8);
    arr[0]->push_back(8);
    arr[0]->push_back(8);
    arr[1]->push_back(9);
    arr[1]->push_back(9);
    arr[1]->push_back(9);
    arr[2]->push_back(10);
    arr[2]->push_back(10);
    arr[2]->push_back(10);
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i]->at(j) << " ";
        }
        cout << endl;
    }
    
    delete arr[1];
    arr[1] = nullptr;
    cout << "Bleh!" << endl;
    
    for (int i = 0; i < 3; i++){
        if (arr[i] != nullptr){
            for (int j = 0; j < arr[i]->size(); j++){
                cout << arr[i]->at(j) << " ";
            }
            cout << endl;
//            i++;
        } else {
//            i++;
        }
    }
    
//    int* arr;
//    arr = new int[5];
//    arr[0] = 1;
//    arr[1] = 2;
//    arr[2] = 3;
//    arr[3] = 4;
//    arr[4] = 5;
//    cout << "test" << endl;
//    for (int i = 0; i < 5; i++)
//        cout << arr[i] << " ";
    
//    cout << 1/2 << endl;
    
//    Test t;
//    t.Print();
//    cout << " **************** " << endl;
//    t.Insert(1);
//    t.Insert(2);
//    t.Insert(3);
//    t.Insert(4);
//    t.Insert(14);
//    t.Insert(24);
//    t.Insert(5);
//    t.Print();
//    cout << endl;
    
    return 0;
}
