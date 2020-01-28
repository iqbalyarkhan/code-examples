//
//  BinaryTree.h
//  Test_UVA
//
//  Created by Iqbal Khan on 1/26/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template<typename T>
class BinaryTree{
private:
    class Node{
    public:
        Node* left;
        Node* right;
        T item;
    };
    Node* root;
    int size;
    void InOrderTraversal(Node* curr);
    void PreOrderTraversal(Node* curr);
    void RecursiveInsert(Node*& curr, T newItem);
    Node* GetSuccessor(Node *);
public:
    BinaryTree();
    void Insert(T newItem);
    bool Find(T itemToFind);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
    T FindMax();
    T FindMin();
    void Delete(T itemToDelete);
    
};

template<typename T>
BinaryTree<T>::BinaryTree(){
    root = nullptr;
    size = 0;
}

template<typename T>
void BinaryTree<T>::Insert(T newItem){
    size++;
    RecursiveInsert(root, newItem);
//    Node* newNode = new Node;
//    newNode->item = newItem;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//    if (root == nullptr){
//        root = newNode;
//    } else {
//        Node* curr = root;
//        Node* prev = root;
//        while (curr != nullptr){
//            prev = curr;
//            if (newItem < curr->item){
//                curr = curr->left;
//            } else {
//                curr = curr->right;
//            }
//        }
//
//        if (newItem < prev->item)
//            prev->left = newNode;
//        else
//            prev->right = newNode;
//    }
}

template<typename T>
void BinaryTree<T>::RecursiveInsert(Node*& curr, T newItem){
    if (curr == nullptr){
        Node* newNode = new Node;
        newNode->item = newItem;
        newNode->left = nullptr;
        newNode->right = nullptr;
        curr = newNode;
        return;
    }
    if (newItem < curr->item)
        RecursiveInsert(curr->left, newItem);
    if (newItem > curr->item)
        RecursiveInsert(curr->right, newItem);
}

template<typename T>
void BinaryTree<T>::InOrderTraversal(){
    BinaryTree<T>::InOrderTraversal(root);
}

template<typename T>
void BinaryTree<T>::InOrderTraversal(Node* curr){
    if (curr == nullptr){
        return;
    }
    InOrderTraversal(curr->left);
    cout << curr->item << " ";
    InOrderTraversal(curr->right);
}

template<typename T>
void BinaryTree<T>::PreOrderTraversal(){
    BinaryTree<T>::PreOrderTraversal(root);
}

template<typename T>
void BinaryTree<T>::PreOrderTraversal(Node* curr){
    if (curr == nullptr){
        return;
    }
    cout << curr->item << " ";
    PreOrderTraversal(curr->left);
    PreOrderTraversal(curr->right);
}


template<typename T>
bool BinaryTree<T>::Find(T itemToFind) {
    Node* curr = root;
    while (curr != nullptr){
        if (itemToFind < curr->item)
            curr = curr->left;
        else if (itemToFind > curr->item)
            curr = curr->right;
        else
            return true;
    }
    
    return false;
}

template<typename T>
T BinaryTree<T>::FindMax(){
    Node* curr = root;
    while (curr->right != nullptr){
        curr = curr->right;
    }
    return curr->item;
}

template<typename T>
T BinaryTree<T>::FindMin(){
    Node* curr = root;
    while (curr->left != nullptr){
        curr = curr->left;
    }
    return curr->item;
}

template<typename T>
void BinaryTree<T>::Delete(T itemToDelete){

}

#endif /* BinaryTree_h */
