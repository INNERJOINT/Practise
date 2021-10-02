//
//  main.cpp
//  Warpper
//
//  Created by Yukun on 2021/9/18.
//

#include <iostream>
#include <functional>

#include "somedef.hpp"

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main(int argc, const char * argv[]) {
    using namespace std;
    
    /*
     存在问题的调用
     */
    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << " " << use_f(y, dub) << endl;//函数名是指针 类型为double(*)(double)
    cout << "Function pointer square:\n";
    cout << " " << use_f(y, square) << endl;//函数名是指针 类型为double(*)(double)
    cout << "Function object Fp:\n";
    cout << " " << use_f(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << " " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, [](double u){return u * u;}) << endl;
    cout << "Labmda expression 2:\n";
    cout << " " << use_f(y, [](double u){return u + u / 2.0;}) << endl << endl;
    
    /*
     包装器 （warper 也可以叫adapter）
     调用特征标（call signature)： 返回类型以及由括号括起来的参数类型列表
     */
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = square;
    function<double(double)> ef3 = Fp(10.0);
    function<double(double)> ef4 = Fq(10.0);
    function<double(double)> ef5 = [](double u) {return u * u;};
    function<double(double)> ef6 = [](double u) {return u + u / 2.0;};//调用特征标都是double(double)
    cout << "Function pointer dub:\n";
    cout << " " << use_f(y, ef1) << endl;
    cout << "Function pointer square:\n";
    cout << " " << use_f(y, ef2) << endl;
    cout << "Function object Fp:\n";
    cout << " " << use_f(y, ef3) << endl;
    cout << "Function object Fq:\n";
    cout << " " << use_f(y, ef4) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, ef5) << endl;
    cout << "Labmda expression 2:\n";
    cout << " " << use_f(y, ef6) << endl << endl;
    
    //第二种调用方法 通过typedef的方式
    typedef function<double(double)> fdd;
    cout << "Function pointer dub:\n";
    cout << " " << use_f(y, fdd(dub)) << endl;
    cout << "Function pointer square:\n";
    cout << " " << use_f(y, fdd(square)) << endl;
    cout << "Function object Fp:\n";
    cout << " " << use_f(y, fdd(Fp(5.0))) << endl;
    cout << "Function object Fq:\n";
    cout << " " << use_f(y, fdd(Fq(5.0))) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, fdd([](double u){return u * u;})) << endl;
    cout << "Labmda expression 2:\n";
    cout << " " << use_f(y, fdd([](double u){return u + u / 2.0;})) << endl << endl;
    
    //第三种 通过模块化
    cout << "Function pointer dub:\n";
    cout << " " << use_f_fun<double>(y, dub) << endl;
    cout << "Function pointer square:\n";
    cout << " " << use_f_fun<double>(y, square) << endl;//函数名是指针 类型为double(*)(double)
    cout << "Function object Fp:\n";
    cout << " " << use_f_fun<double>(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << " " << use_f_fun<double>(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f_fun<double>(y, [](double u){return u * u;}) << endl;
    cout << "Labmda expression 2:\n";
    cout << " " << use_f_fun<double>(y, [](double u){return u + u / 2.0;}) << endl << endl;
    
    return 0;
}
