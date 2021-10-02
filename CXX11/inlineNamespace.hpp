//
//  inlineNamespace.hpp
//  CXX11
//
//  Created by Yukun on 2021/9/12.
//

#ifndef inlineNamespace_hpp
#define inlineNamespace_hpp

#include <stdio.h>
#include <iostream>
namespace Mine
{
//#include "V99.h"
inline namespace V99
{
void f(int i);
void f(double i);
}

//#include "V98.h"
namespace V98
{
void f(int i);
}
}

#endif /* inlineNamespace_hpp */
