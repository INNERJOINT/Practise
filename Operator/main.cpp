//
//  main.cpp
//  Operator
//
//  Created by Yukun on 2021/9/7.
//

#include <iostream>
#include "Time.hpp"
#include "Vector.hpp"
#include "stonewt.hpp"



int main(int argc, const char * argv[]) {
    using namespace std;
    
    Time plannig, total, adjust;
    Time coding(2, 40);
    Time fixing(5, 55);
    
    cout << "planing time = ";
    plannig.Show();
    
    cout << "coding time = ";
    coding.Show();
    
    cout << "fixing time = ";
    fixing.Show();
    
    // 运算符的两种调用方法
//    total = coding.Sum(fixing);
//    total = coding.operator+(fixing);
    total = coding + fixing;
    //total = total + coding + fixing;//等价于total.operator+(coding+fixing)
    cout << "total time = ";
    total.Show();
    
    adjust = total * 1.5;
//    adjust = 1.5 * total; //报错，成员函数运算符重载定义
    cout << "adjust time = ";
    adjust.Show();
    
    adjust << cout;//调用成员函数方式重载
    cout << adjust << adjust;//调用友元函数方式重载
    
    /*
     一个醉汉走路的例子
     */
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject has the following location:\n" << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    
    /*
     类的自动转换和强制转换
     */
    Stonewt blossem;
//    blossem = 1240;//隐藏转换，利用构造函数将19.6转化为Stonewt类型
    blossem = (Stonewt)19.6;//显式转换
    double pound = (double)blossem;//转换函数
    
    Stonewt jenneySt(20);
    double pennyD = 14.5;
    Stonewt tota;
//    tota = jenneySt + pennyD; //成员函数和友元重载都可以
    /*
     实际上调用为pennyD.operator+(jenneySt)
     如果类型转换和转换函数都可以隐式转换，容易出现二义性
     例如：
     1. pennyD 转换为类对象 调用类的运算符重载
     2. jenneySt 转换为double 加法后得到double再转换赋值给tota
     */
    tota = pennyD + jenneySt; //只有友元可以
    
    return 0;
}
