//
//  MyClass.hpp
//  Typename
//
//  Created by Yukun on 2021/9/11.
//

#ifndef MyClass_hpp
#define MyClass_hpp

#include <stdio.h>
#include <vector>
using namespace std;

template <class T>
class MyClass {
    int i;
    std::vector<int> vi;
    std::vector<int>::iterator vitr;
    
    /*
     需要添加typename的一般情况 前有 T 后有限定T内的::符， 编译器不能确定T内的目标项是类型还是变量
     
     限定名
     1. cout end 限定名
     2. using std::cout;using std::endl后， cout end 不是限定名
     
     依赖名 依赖于模版参数的名称
     T, vector<T>, vector<T>::iterator 都是依赖名
     */
    T t;
    std::vector<T> vt;
    typename vector<T>::iterator viter;
};

#endif /* MyClass_hpp */
