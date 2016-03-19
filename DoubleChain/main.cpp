//
//  main.cpp
//  DoubleChain
//
//  Created by David on 16/3/19.
//  Copyright (c) 2016年 David. All rights reserved.
//

#include <iostream>
#include "Chain_m.h"

using namespace std;
int main() {
    Chain<int> c;
    for (int i=0; i<10; i++) {
        c.insert(i, (i+1)*2);
    }
    c.print();
    c.remove(4);
    cout<<c.length()<<endl;
    c.print();
    cout<<c.indexOfObject(12)<<endl;
    cout<<c.objectAtIndex(6)<<endl;
    c.clear();
    if (c.isEmpty()) {
        c.remove(0);
    }
}
