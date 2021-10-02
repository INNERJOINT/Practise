//
//  main.cpp
//  TypeOf
//
//  Created by Yukun on 2021/9/26.
//

#include <iostream>

/*
 typeof(目前只有gcc支持，待考证）
 */
template<class A, class B>
typeof((*(A*)0)*(*(B*)0)) operator*(A a,B b);

#define max(a,b)\
({\
typeof(a) _a = (a);\
typeof(b) _b = (b);\
_a > _b ? _a : _b;\
})

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int a = max(4,6);
    
    return 0;
}
