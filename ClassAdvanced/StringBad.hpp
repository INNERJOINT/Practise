//
//  StringBad.hpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#ifndef StringBad_hpp
#define StringBad_hpp

#include <stdio.h>
#include <iostream>

/*
 特殊成员函数
 1. 默认构造函数
 2. 默认析构函数
 3. 复制构造函数
    StringBad(nonst StringBad &);
    主要在生成临时对象时调用
    调用复制构造函数的情况 1. 函数按值传参 2.函数返回对象
    1. StringBad ditto(motto);
    2. StringBad metto = motto;
    3. StringBad also = StringBad(motto);
    4. StringBad * pStringBad = new StringBad(motto);
 4. 赋值构造函数
 5. 地址运算符
 6. 移动构造函数（C++11)
 7. 移动赋值运算符 (C++11)
 */

class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const StringBad &);
    StringBad & operator=(const StringBad &);
    StringBad(const char * s);
    StringBad();
    //默认参数 效果同样一个默认构造函数
    //下面都是默认构造函数
    //StringBad(int n = 0){}
    //StringBad(int n = 0, char b = '0'){}
    ~StringBad();
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif /* StringBad_hpp */
