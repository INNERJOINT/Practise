//
//  stonewt.hpp
//  Operator
//
//  Created by Yukun on 2021/9/8.
//

#ifndef stonewt_hpp
#define stonewt_hpp

#include <stdio.h>

class Stonewt{
private:
    static const int Lbs_per_stn = 14;
    int stone;
    double pds_left;
    double pounds;
public:
    /*
     explicit 关闭隐式自动转换
     否则可能存在如下的隐式转化：
     1. Stonewt对象初始化为           double Stonewt a = 18.4;
     2. double值赋值给Stonewt对象。   Stonewt a;a= 18.5;
     3. 接收Stonewt参数的函数         print(Stonewt a);print(18.6);
     4. 返回值为Stonewt类型           Stonewt print(){return 18.7;}
     5. 在不存在二义性的前提夏，上述可转化为double的内置类型时
        Stonewt a;a= 18;(a->18.0);如果Stonewt(long lbs)不是explicit则会出现二义性。
     */
    Stonewt(double lbs);
    explicit Stonewt(long lbs);
    explicit Stonewt(int stn, double lbs = 0);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    /*
     转化函数
     1. 必须是类方法
     2. 不指定返回值
     3. 不能有参数
     
     同样的，转换函数也可以自动隐藏转换，也存在上述的问题。
     */
    explicit operator double() const;
    
    /*
     Stonewt jenneySt();
     double pennyD = 14.5;
     Stonewt total;
     total = jenneySt + pennyD //成员函数和友元重载都可以
     total = penneyD + jenneySt //只有友元可以
     */
//    Stonewt operator+(const Stonewt& t) const;
    friend Stonewt operator+(const Stonewt & t,const Stonewt & p);
    
};

#endif /* stonewt_hpp */
