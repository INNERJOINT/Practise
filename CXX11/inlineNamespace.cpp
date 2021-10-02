//
//  inlineNamespace.cpp
//  CXX11
//
//  Created by Yukun on 2021/9/12.
//

#include "inlineNamespace.hpp"

namespace Mine
{
//#include "V99.h"
inline namespace V99
{
void f(int i)
{std::cout << "V99 in V99.h\n";}
void f(double i)
{std::cout << "V99 new function in V99.h\n";}
}

//#include "V98.h"
namespace V98
{
void f(int i)
{std::cout << "basic version in V98.h\n";}
}
}
