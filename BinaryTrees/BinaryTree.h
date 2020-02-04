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
    void PostOrderTraversal(Node* curr);
    void RecursiveInsert(Node*& curr, T newItem);
    void FindMin(Node*curr);
    Node* RecursiveDeletePrivate(Node*, T);
    
public:
    BinaryTree();
    void Insert(T newItem);
    bool Find(T itemToFind);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
    T FindMax();
    T FindMin();
    void RemoveNode(T itemToDelete);
    void RecursiveDelete(T itemToDelete);
    
};

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::RecursiveDeletePrivate(Node* root, T itemToDelete){
    if (root == nullptr){
        return nullptr;
    } else if (itemToDelete < root->item){
        root->left = RecursiveDeletePrivate(root->left, itemToDelete);
    } else if (itemToDelete > root->item){
        root->right = RecursiveDeletePrivate(root->right, itemToDelete);
    } else {
        //We found the item.
        if (root->left == nullptr && root->right == nullptr){
            //It is a leaf node
            delete root;
            root = nullptr;
            return root;
            
        } else if (root->left == nullptr){
            //Node to be deleted has right children
            Node* temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
            return root;
            
        } else if (root->right == nullptr){
            //Node to be deleted has left children
            Node* temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
            return root;
        } else{
            //Node to be deleted has 2 children - left and right
            //Find min in right subtree
            Node* temp = root->right;
            
            while (temp->left != nullptr){
                temp = temp->left;
            }
            
            root->item = temp->item;
            root->right = RecursiveDeletePrivate(root->right, temp->item);
            
        }
    }
    return root;
}

template <typename T>
void BinaryTree<T>::RecursiveDelete(T itemToDelete){
    //Need to capture returned root because we might be
    //deleting the actual root during the delete operation
    root = RecursiveDeletePrivate(root, itemToDelete);
}

template<typename T>
void BinaryTree<T>::RemoveNode(T itemToDelete){
    RemoveNodePrivate(root, itemToDelete);
}

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
void BinaryTree<T>::PostOrderTraversal(){
    BinaryTree<T>::PostOrderTraversal(root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraversal(Node* curr){
    if (curr == nullptr){
        return;
    }
    PostOrderTraversal(curr->left);
    PostOrderTraversal(curr->right);
    cout << curr->item << " ";
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

template <typename T>
void BinaryTree<T>::FindMin(Node *curr){
    Node* newCurr = curr->right;
    Node* newPrev = curr;
    while (newCurr->left != nullptr){
        newPrev = newCurr;
        newCurr = newCurr->left;
    }
    
    curr->item = newCurr->item;
    if (newCurr->right != nullptr){
        newPrev->left = newCurr->right;
    } else {
        newPrev->left = nullptr;
    }
    
    delete newCurr;
    newCurr = nullptr;
}

#endif /* BinaryTree_h */
