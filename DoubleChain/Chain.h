//
//  Chain.h
//  DoubleChain
//
//  Created by David on 16/3/19.
//  Copyright (c) 2016年 David. All rights reserved.
//
#include <iostream>
using namespace std;

template <class elementType>
class Chain{
private:
    struct node{
        elementType data;
        node *prev, *next;
        node(const elementType &x, node *p = NULL, node *n = NULL){
            data = x;
            next = n;
            prev = p;
        }
        node():next(NULL), prev(NULL){}
        ~node(){}
    };
    node *head,*tail;
    int currentLength;
    //node *move(int i) const;
public:
    Chain();
    ~Chain(){
        clear();
        delete head;
        delete tail;
    }
    
    void clear();
    int length();
    bool isEmpty();
    void insert(int index, const elementType &newElement);
    void remove(int index);
    int indexOfObject(const elementType &e);
    elementType objectAtIndex(int index);
    void print();
    
};

