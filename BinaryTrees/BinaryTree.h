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
    Node* newNode = new Node;
    newNode->item = newItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (root == nullptr){
        root = newNode;
    } else {
        Node* curr = root;
        Node* prev = root;
        while (curr != nullptr){
            prev = curr;
            if (newItem < curr->item){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        if (newItem < prev->item)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
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
    size--;
    Node* nodeToBeDeleted = root;
    Node* prev = nullptr;
    /*
     First find the node we need to delete
     while maintaining prev and curr pointers
     */
    while (nodeToBeDeleted != nullptr){
        if (itemToDelete < nodeToBeDeleted->item){
            //Item less than curr: look in left subtree
            prev = nodeToBeDeleted;
            nodeToBeDeleted = nodeToBeDeleted->left;
        } else if (itemToDelete > nodeToBeDeleted->item) {
            //Item greater than curr: look in right subtree
            prev = nodeToBeDeleted;
            nodeToBeDeleted = nodeToBeDeleted->right;
        } else {
            //We found the item
            break;
        }
    }
    
    //nodeToBeDeleted now is pointing to the node to be deleted
    //and prev is pointing either to null or parent of
    //nodeToBeDeleted
    
    /**
     Determine the type of node we're deleting:
     -leaf
     -node with 1 child
     -node with 2 children
     */
    if (nodeToBeDeleted->left == nullptr && nodeToBeDeleted->right == nullptr){
        //Deleting a leaf:
        if (prev->left == nodeToBeDeleted){
            prev->left = nullptr;
        } else {
            prev->right = nullptr;
        }
        delete nodeToBeDeleted;
        nodeToBeDeleted = nullptr;
    } else if (nodeToBeDeleted->left == nullptr || nodeToBeDeleted->right == nullptr){
        //Deleting node with just one child
        Node* temp = nullptr;
        nodeToBeDeleted->right == nullptr ? temp = nodeToBeDeleted->left : temp = nodeToBeDeleted->right;
        
        if (nodeToBeDeleted == prev->right){
            delete nodeToBeDeleted;
            nodeToBeDeleted = nullptr;
            prev->right = temp;
        } else {
            delete nodeToBeDeleted;
            nodeToBeDeleted = nullptr;
            prev->left = temp;
        }
    } else {
        //Deleting node with 2 children
        Node* replaceWith = nodeToBeDeleted->right;
        Node* newPrev = nodeToBeDeleted->right;
        while (replaceWith->left != nullptr){
            newPrev = replaceWith;
            replaceWith = replaceWith->left;
        }
        
        if (replaceWith->right != nullptr){
            newPrev->left = replaceWith->right;
        } else {
            newPrev->left = nullptr;
        }
        replaceWith->left = nodeToBeDeleted->left;
        replaceWith->right = nodeToBeDeleted->right;
        if (prev != nullptr){
            if (nodeToBeDeleted == prev->right){
                prev->right = replaceWith;
            } else {
                prev->left = replaceWith;
            }
        } else {
            //We're deleting root
            root = replaceWith;
        }
        
        delete nodeToBeDeleted;
        nodeToBeDeleted = nullptr;
    }
}

#endif /* BinaryTree_h */
