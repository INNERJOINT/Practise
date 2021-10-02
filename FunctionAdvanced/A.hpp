//
//  A.hpp
//  FunctionAdvanced
//
//  Created by Yukun on 2021/9/9.
//

#ifndef A_hpp
#define A_hpp

#include <stdio.h>
#include <iostream>

class A{
public:
    void foo() const {std::cout << "A::foo() const \n";}
    void foo() { std::cout << "A::foo()\n";}
};

#endif /* A_hpp */
