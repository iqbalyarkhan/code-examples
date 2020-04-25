//
//  main.cpp
//  Struct
//
//  Created by Iqbal Khan on 4/25/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include "includes.h"


// Definition for singly-linked list.
template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
    
};

void DeleteAfter(){
    
}

shared_ptr<ListNode<int>> Search(shared_ptr<ListNode<int>> l, int key){
   shared_ptr<ListNode<int>> ptr = l;
    while (l && l->data != key){
        l = l->next;
    }
    
    return l;
}

void AppendNode(shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> *tail){
    (*tail)->next = *node;
    *tail = *node; //point tail to the newly added node
    *node = (*node)->next; //Increment whichever pointer was passed in
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2){
    shared_ptr<ListNode<int>> dummyHead(new ListNode<int>);
    auto tail = dummyHead;
    
    while (l1 && l2){
        AppendNode(l1->data <= l2->data ? &l1 : &l2, &tail);
        cout << "Dummy head as of now: " << endl;
        auto temp = dummyHead;
        while (temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    tail->next = l1 ? l1 : l2;
    cout << "Dummy before returingin: " << endl;
    auto temp = dummyHead;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return dummyHead->next;
}



int main(int argc, const char * argv[]) {
    shared_ptr<ListNode<int>> head(new ListNode<int>);
    head->data = 1;
    shared_ptr<ListNode<int>> l(new ListNode<int>);
    l->data = 5;
    head->next = l;
    shared_ptr<ListNode<int>> m(new ListNode<int>);
    m->data = 11;
    shared_ptr<ListNode<int>> n(new ListNode<int>);
    n->data = 13;
    shared_ptr<ListNode<int>> o(new ListNode<int>);
    o->data = 14;
    head->next = l;
    head->next->next = m;
    head->next->next->next = n;
    head->next->next->next->next = o;
    shared_ptr<ListNode<int>> temp1 = head;
    
    
    shared_ptr<ListNode<int>> head2(new ListNode<int>);
    head2->data = 3;
    shared_ptr<ListNode<int>> a(new ListNode<int>);
    a->data = 6;
    head->next = l;
    shared_ptr<ListNode<int>> b(new ListNode<int>);
    b->data = 12;
    shared_ptr<ListNode<int>> c(new ListNode<int>);
    c->data = 13;
    shared_ptr<ListNode<int>> d(new ListNode<int>);
    d->data = 15;
    head2->next =a;
    head2->next->next = b;
    head2->next->next->next = c;
    head2->next->next->next->next = d;
    shared_ptr<ListNode<int>> temp2 = head2;
    cout  << "l1: ";
        while (temp1){
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }
        cout << endl;
    cout << "l2: ";
        while (temp2){
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }
        cout << endl;
    auto ans = MergeTwoSortedLists(head, head2);
    cout << "bleh" << endl;

    
//    auto ret = Search(head, 23);
//    if (ret){
//        cout << "Yay! found: " << ret->data << endl;
//    } else {
//        cout << "not found! :(" << endl;
//    }
    
    return 0;
}
