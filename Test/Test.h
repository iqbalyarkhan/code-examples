//
//  Test.h
//  Test_UVA
//
//  Created by Iqbal Khan on 2/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef Test_h
#define Test_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Test{
private:
    class Node{
        public:
            Node* next;
            int data;
    };
    vector<Node*> table;
    int size;
    int HashFunction(int item);
public:
    Test();
    void Insert(int item);
    void Print();
};

Test::Test(){
    for (int i = 0; i < 10; i++){
        table.push_back(nullptr);
    }
    
    size = int(table.size());
}

int Test::HashFunction(int item){
    return (item % size);
}

void Test::Print(){
    for (int i = 0; i < size; i++){
        if (table[i] != nullptr){
            Node* curr = table[i];
            cout << i << " --> ";
            while (curr != nullptr){
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        } else {
            cout << i << " --> " << "nullptr" << endl;
        }
    }
}

void Test::Insert(int item){
    Node* temp = new Node;
    temp->data = item;
    temp->next = nullptr;
    int position = HashFunction(item);
    if (table[position] == nullptr){
        table[position] = temp;
    } else {
        Node* curr = table[position];
        while (curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
    }
}




#endif /* Test_h */
