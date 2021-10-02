//
//  main.cpp
//  _Attribute
//
//  Created by Yukun on 2021/9/4.
//

#include <iostream>
#include "visibility.hpp"
/*
 对齐
 1. aligned
 2. packed
 */
struct S{
    short b[3];
}__attribute__((aligned(16)));

struct Y{
    short b[3];
};

struct X{
    short b[3];
}__attribute__((packed));

int main(int argc, const char * argv[]) {
    using namespace std;
    
    cout << "sizeof struct S (aliged): " << sizeof(S) << endl;
    cout << "sizeof struct Y : " << sizeof(Y) << endl;
    cout << "sizeof struct X (packed): " << sizeof(X) << endl;
    
    not_hidden();
    return 0;
}
