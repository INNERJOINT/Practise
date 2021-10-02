//
//  Stock.hpp
//  Class
//
//  Created by Yukun on 2021/9/5.
//

#ifndef Stock_hpp
#define Stock_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Stock{
private:
    std::string m_company;
    long m_shares;
    double m_share_val;
    double m_total_val;
    static int* heap;
    void set_tot(){ m_total_val = m_shares * m_share_val; }//直接定义，内联函数
public:
    Stock();
    ~Stock();
    Stock(const std::string &co, long n = 0, double pr = 0);//构造函数默认值需要声明时给出
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    /*
     对常成员函数的理解
     函数最后的const用于修饰this指针，
     而函数内部调用其他成员函数，本质上是为this->update()
     因此，常成员函数不能修改成员变量，使用非常成员函数
     而且，如果某个实例为const，也只能调用常成员函数，这样才能保证才变量不会修改任何数据
     */
    void show() const;
    const Stock & topval(const Stock &) const;
};

/*
 类常量的两种方法
 1. 枚举 enum
 2. 静态常量 static const
 */
class Bakery{
private:
//    static const int Months = 12;
    enum {Months = 12};
    double costs[Months];
};

/*
 作用域内枚举
 枚举分类：1.常规枚举 可自动隐式转化为int 2.作用域内枚举 不能隐式转化
 一般编译器枚举的底层类型为int，也可能是其他类型
 1. 枚举量相同 需要添加枚举作用域 添加class或struct
 */
/*
 枚举类
 */
enum class egg
{
    Small,
    Medium,
    Large,
    Jumbo
};

enum struct apple{
    Small,
    Medium,
    Large,
    Jumbo
};

enum class t_shirt{
    Small,
    Medium,
    Large,
    Xlarge
};


#endif /* Stock_hpp */
