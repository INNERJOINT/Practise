//
//  Time.hpp
//  Operator
//
//  Created by Yukun on 2021/9/7.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <iostream>

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    /*
     返回值不应为Time &引用，因为该引用在代码块结束时会被释放而丢失数据，除非引用目标为一段new内存块
     */
    Time Sum(const Time &) const;
    Time operator+(const Time &) const;
    /*
     友元函数，不是类的成员函数，但有成员函数相同的权限
     */
    Time operator*(double n) const; //成员函数形式的重载，存在局限性 类项需为第一个操作数 调用顺序为Time * n， n * Time会报错
    friend Time operator*(double n, const Time &t);
    /*
     这是一个Time类的友元函数 而不是ostream类的友元
     需要访问哪些类的成员，就定义为哪些类的友元
     */
    void Show() const;
    void operator<<(std::ostream &os)const;
    friend std::ostream & operator<<(std::ostream &os, const Time &t);
};

#endif /* Time_hpp */
