//
//  inlineNamespace.hpp
//  Namespace
//
//  Created by Yukun on 2021/9/12.
//

#ifndef inlineNamespace_hpp
#define inlineNamespace_hpp

#include <stdio.h>
#include <iostream>

namespace inline_test {
//显式内联
inline namespace inline_namespace1{
class Inline1{
    public :
    int iv;
};
}
//隐式内联
namespace inline_namespace1 {
class Inline2{
public:
    double dv;
};
}

void test_inline_namespace(){
    Inline1 in1;
    in1.iv = 5;
    
    Inline2 in2;
    in2.dv = 2;
}
}

namespace ver1 {
class A{
public:
    void fun1(){}
};
}

namespace ver1 {
class B{
public:
    void fun2(){}
};
}

inline namespace ver2 {
class A{
public:
    void fun2(){}
};
}

namespace ver2 {
class B{
public:
    void fun1(){}
};
class C{
public:
    void fun3(){}
};
}
#endif /* inlineNamespace_hpp */
