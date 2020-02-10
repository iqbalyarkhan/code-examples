//
//  HashTable.h
//  Test_UVA
//
//  Created by Iqbal Khan on 2/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class HashTable{
private:
    class Node{
    public:
        Node* next;
        T item;
    };
    int size;
    Node* root;
    vector<Node*> table;
    int HashFunction(T item);
    
public:
    HashTable();
    void Insert(T item);
    void PrintTable();
};

template <typename T>
HashTable<T>::HashTable(){
    //Initializing our table with 10 null items
    for (int i = 0; i < 10; i++){
        table.push_back(nullptr);
    }
    size = int(table.size());
}

template <typename T>
void HashTable<T>::Insert(T item){
    //Getting position
    int position = HashFunction(item);
    //Creating a temp node
    Node* temp = new Node;
    temp->item = item;
    temp->next = nullptr;
    //Checking if collision
    if (table[position] == nullptr){
        //No collision, just add item
        table[position] = temp;
    } else {
        //Collision..
        Node* curr = table[position];
        //Use separate chaining and append
        //to end
        while (curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
    }
}

template <typename T>
int HashTable<T>::HashFunction(T item){
    //Simple modulus hash function
    return (item % size);
}

template <typename T>
void HashTable<T>::PrintTable(){
    //Printing table for sanity check
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


#endif /* HashTable_h */
