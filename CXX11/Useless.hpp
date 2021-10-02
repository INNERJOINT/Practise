//
//  Useless.hpp
//  CXX11
//
//  Created by Yukun on 2021/9/11.
//

#ifndef Useless_hpp
#define Useless_hpp

#include <stdio.h>
#include <iostream>
/*
 右值引用用例
 */
class Useless
{
private:
    int n;
    char *pc;
    static int ct;
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless &f); //拷贝构造
    Useless(Useless &&f); // 移动构造
    ~Useless();
    Useless operator+(const Useless & f) const;
    Useless & operator=(const Useless & f);// 赋值
    Useless & operator=(Useless && f);// 移动赋值
    void ShowData() const;
};

#endif /* Useless_hpp */
