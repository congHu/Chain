//
//  Chain_m.h
//  DoubleChain
//
//  Created by David on 16/3/19.
//  Copyright (c) 2016年 David. All rights reserved.
//
#include <iostream>
#include "Chain.h"
using namespace std;

template <class elementType>
Chain<elementType>::Chain(){
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
}
template <class elementType>
void Chain<elementType>::clear(){
    node *p = head->next, *q;
    head->next = tail;
    tail->prev = head;
    while (p!=tail) {
        q = p->next;
        delete p;
        p=q;
    }
    currentLength = 0;
}
template <class elementType>
int Chain<elementType>::length(){
    return currentLength;
}
template <class elementType>
bool Chain<elementType>::isEmpty(){
    if (head->next == tail) {
        return true;
    }else{
        return false;
    }
}

template <class elementType>
void Chain<elementType>::insert(int index, const elementType &newElement){
    if (index<0||index>currentLength) {
        cout<<"Out of range.\n";
    }else{
        node *p = head->next;
        while (index--) {
            p = p->next;
        }
        node *n = new node(newElement, p->prev, p);
        p->prev->next = n;
        p->prev = n;
        ++currentLength;
    }
    
}
template <class elementType>
void Chain<elementType>::remove(int index){
    if (index<0||index>=currentLength) {
        cout<<"Out of range.\n";
    }else{
        node *p = head->next;
        while (index--) {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --currentLength;
    }
}
template <class elementType>
int Chain<elementType>::indexOfObject(const elementType &e){
    node *p = head->next;
    for (int index = 0; p != tail; index++) {
        if (p->data == 0) {
            return index;
        }
        p = p->next;
    }
    return NULL;
    
}
template <class elementType>
elementType Chain<elementType>::objectAtIndex(int index){
    if (index<0||index>=currentLength) {
        cout<<"Out of range.\n";
        return NULL;
    }else{
        node *p = head->next;
        while (index--) {
            p = p->next;
        }
        return p->data;
    }
}
template <class elementType>
void Chain<elementType>::print(){
    node *p = head->next;
    while (p!=tail) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


