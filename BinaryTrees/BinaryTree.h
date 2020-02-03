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
    void Delete(Node*, T);//RemoveNodePrivate()
    void DeleteRoot();
    void RemoveNode(Node*, Node*, bool);
    
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

template <typename T>
void BinaryTree<T>::RemoveNode(Node* prev, Node* curr, bool left){
    //curr is node to be deleted
    //prev is parent of curr
    //left is to tell relationship b/w prev and curr
    if (curr->left == nullptr && curr->right == nullptr){
        if (left){
            delete prev->left;
            prev->left = nullptr;
        } else {
            delete prev->right;
            prev->right = nullptr;
        }
    } else if (curr->left != nullptr && curr->right == nullptr){
        if (left){
            prev->left = curr->left;
        } else {
            prev->right = curr->left;
        }
        delete curr;
        curr = nullptr;
    } else if (curr->left == nullptr && curr->right != nullptr){
        if (left){
            prev->left = curr->right;
        } else {
            prev->right = curr->right;
        }
        delete curr;
        curr = nullptr;
    } else {
        Node* temp = curr->right;
        while (temp->left != nullptr){
            temp = temp->left;
        }
        
        curr->item = temp->item;
        Delete(curr, curr->item);
        
    }
}

template<typename T>
void BinaryTree<T>::DeleteRoot(){
    if (root != nullptr){
        Node* temp = root;
        //If root has no children
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            return;
        } else if (temp->left != nullptr && temp->right == nullptr ){
            //Root has only left children
            temp = temp->left;
            delete root;
            root = temp;
        } else if (temp->left == nullptr && temp->right != nullptr) {
            //Root has only right children
            temp = temp->right;
            delete root;
            root = temp;
        } else {
            //Root has 2 children
            temp = temp->right;
            while (temp->left != nullptr){
                temp = temp->left;
            }
            root->item = temp->item;
            Delete(root, temp->item);
        }
    } else {
        cout << "Tree is empty" << endl;
    }
}

template<typename T>
void BinaryTree<T>::Delete(Node* curr, T itemToDelete){
    if (curr->item == itemToDelete){
        //We've found the item in root.
        DeleteRoot();
    } else {
        //Item not in root
        if (itemToDelete < curr->item && curr->left != nullptr){
            //Look in left subtree
            //RemoveNode takes in curr, the child of curr and bool to tell if left child is being passed
            curr->left->item == itemToDelete ? RemoveNode(curr,curr->left,true) : Delete(curr->left, itemToDelete);
            
        } else if (itemToDelete > curr->item && curr->right != nullptr){
            //Look in right subtree
            curr->right->item == itemToDelete ? RemoveNode(curr, curr->right, false) : Delete(curr->right, itemToDelete);
            
        } else {
            //Key not present
            cout << "Key: " << itemToDelete << " not present in tree" << endl;
        }
        
    }
}

template<typename T>
void BinaryTree<T>::Delete(T itemToDelete){
    Delete(root, itemToDelete);
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
