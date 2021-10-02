//
//  main.cpp
//  FunctionAdvanced
//
//  Created by Yukun on 2021/9/9.
//

#include <iostream>

#include "A.hpp"
#include "Intvec.hpp"

/*
 仅当参数为const时才能产生临时变量
 */
double refcube(const double &ra){
    return ra * ra * ra;
}

int globalvar = 20;
int& foo(){
    return globalvar;
}

A bar() {return A();}
const A cbar(){return A();}

unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main(int argc, const char * argv[]) {
    using namespace std;
    /*
     临时变量 仅当参数为const时
     1. 实参类型正确，但不是左值
        左值: 可以被引用的数据对象，变量、数据元素、结构成员、引用、解除引用
     2. 实参类型不正确，但可被转换为正确的类型
     */
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 5L;
    double len[4] = {2.0, 5.0, 10.0, 12.0};
    //类型正确，而且是左值
    double c1 = refcube(side);
    double c2 = refcube(*pd);
    double c3 = refcube(rd);
    double c4 = refcube(len[2]);
    //生成一个临时变量
    double c5 = refcube(edge);
    double c6 = refcube(7.0);
    double c7 = refcube(side + 10.0);
    
    /*
     左值 和 右值（又可以分为纯右值 pure value,pvalue 和 将亡值 expiring value,xvalue)
     1. c++98增加了引用， 又称为左值引用
        1. 不允许为右值创建非常量引用，当允许创建常量引用 const int & p = 10;
     2. c++11增加了右值引用，用于语义移动和完美转发
        1. 基本上右值引用都是非常量，常量的话与右值引用的目的相违背
     lvalue(locator value)
     rvalue(read value)
     1. 左值 占据内存中某个可识别的位置（地址）
     2. 右值 不表示内存中某个可识别对象（一般寄存器或者和代码块存储在一起）
     */
    foo() = 10;
    cout << globalvar << endl;
    
    //左值到右值的隐式转换
    int a = 1;
    int b = 2;
    int c = a + b;// + 需要两个右值，a b 隐式转换为右值
    
    //右值显式转左值
    int arr[] = {1, 2};
    int *p = &arr[0];
    *(p + 1) = 10;// * 需要右值参数，但返回左值
    int *addr =  &a;// & 需要左值参数，但返回右值
    
    /*
     CV限定
     A bar() {return A();}
     const A cbar(){return A();}
     void foo() const {std::cout << "A::foo() const \n";}
     void foo() { std::cout << "A::foo()\n";}
    */
    bar().foo();
    cbar().foo();//返回右值，且const限定修饰
    
    //1.如果变量已经实例化则调用赋值操作符
    //2.如果变量在实例化过程中则调用拷贝构造函数
    Intvec v1(20);
    Intvec v2;
    
    cout << "assinging lvalue..\n";
    //v2 = v1;
    v2 = Intvec(33);
    cout << "ended assigning lvalue..\n";
    
    /*
     函数重载
     */
    char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char * temp;
    
    for (i = 1; i < 10; i++) {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }
    
    
    return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;
    
    if (ct == 0 or num == 0) {
        return 0;
    }
    while (n /= 10) {
        digits++;
    }
    if (digits > ct) {
        ct = digits - ct;
        while (ct--) {
            num /= 10;
        }
        return num;
    }else{
        return num;
    }
}

char * left(const char * str, int n){
    if (n < 0) {
        n = 0;
    }
    char * p = new char[n + 1];
    int i;
    for (i = 0; i < n and str[i]; i++) {
        p[i] = str[i];
    }
    while (i <= n) {
        p[i++] = '\0';
    }
    return p;
}
