//
//  Trie.h
//  Test_UVA
//
//  Created by Iqbal Khan on 4/4/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Trie{
private:
    //A node class
    class Node{
    public:
        int value;
        vector<Node*> links;
    };
    Node* root;
    int alphabetSize;
    void Collect(Node*);
    
public:
    Trie(int);
    void Put(string,int);
    void Print();
    void Collect();
};

Trie::Trie(int s) : alphabetSize(s){
    root = new Node;
    root->value = -1;
    root->links.resize(alphabetSize);
}

void Trie::Put(string key, int val){
    Node* curr = root;
    int index = 0;
    for (int i = 0; i < key.size(); i++){
        index = int(key[i]) - 97;
        if (curr->links[index] == nullptr){
            //We're adding this character for the first time
            Node* newNode = new Node;
            newNode->links.resize(alphabetSize);
            curr->links[index] = newNode;
            curr = newNode;
        } else {
            //Already added by previous addition,
            //follow the link
            curr = curr->links[index];
        }
    }
    curr->value = val;
}

void Trie::Collect(){
    Node* curr = root;
    Collect(curr);
}

//void Trie::Collect(Node* curr){
//    for (int i = 0; i < curr->inde)
//}

#endif /* Trie_h */
