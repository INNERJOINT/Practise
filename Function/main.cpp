//
//  main.cpp
//  Function
//
//  Created by Yukun on 2021/8/31.
//

#include <iostream>

using namespace std;

/*
 原型
 在C中 原型是可选的
 在C++中 原型不是可选的 因此需要在使用函数前存在函数原型

 1. 在C++中 括号为空与void相同 如果不指定参数列表 应添加省略号 void said_hi(...);
 2. 在ANSI C中 为空意味着后面定义参数列表 void said_hi(void);
 */
void said_hi();
void cheers(int);
double cube(double x);

/*
 函数指针
 由于()优先级比*高，因此
 1. double （*pf)(int); //pf是一个函数指针
 2. double *pf(int); //pf是一个返回double指针的函数
 */
void (*fp)(void);

/*
 以下三种原型都是一样的
 */
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main(int argc, const char * argv[]) {
    
    fp = said_hi;
    //使用函数指针调用函数的两种方式
    fp();
    (*fp)();
    
    /*
     
     */
    double av[3] = {1112.3, 1532.4, 2248.9};
    
    const double *(*p1)(const double *, int) = f1;//最快方法，直接将函数原型的函数名替换
    auto p2 = f2;//c++11后 使用auto自动推断
    
    cout << "Using pointers to functions:\n";
    cout << "Address Value\n";
    cout << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << " : " << *p2(av, 3) << endl;
    
    //定义函数指针数组
    const double * (*pa[3])(const double *, int) = {f1, f2, f3};
    //auto pb = {f1,f2,f3}; 自动推断不支持初始化列表，只能单值初始化
    //可以使用自动推断auto
    //或者使用双指针 **
    //auto pb = pa;
    const double * (**pb)(const double *, int) = pa;
    
    //使用数组的方式
    cout << "\nUsing an array of pointers to functions:\n";
    cout << "Address Value\n";
    for (int i = 0; i < 3; i++) {
        //两种方法 pa[i]() 和 (*pa[i])()
//        cout << pa[i](av, 3) << " : " << *pa[i](av, 3) << endl;
        cout << (*pa[i])(av, 3) << " : " << *(*pa[i])(av, 3) << endl;
    }
    //使用指针的方式
    cout << "\nUsing an pointer to a pointer to functions:\n";
    cout << "Address Value\n";
    for (int i = 0; i < 3; i++) {
        //同样有两种方法
        cout << pb[i](av, 3) << " : " << *pb[i](av, 3) << endl;
//        cout << (*pb[i])(av, 3) << " : " << *(*pb[i])(av, 3) << endl;
    }
    
    //使用数组指针的方式
    //同样可以使用auto 或者 双指针
    //auto pc = &pa;
    const double * (*(*pc)[3])(const double *, int) = &pa;
    cout << "\nUsing an pointer to an array of function pointers:\n";
    cout << "Address Value\n";
    for (int i = 0; i < 3; i++) {
        //pc是指向数组的指针
        //因此*pc即该数组 (*pc)[i]即数组中的元素
        cout << (*pc)[i](av, 3) << " : " << *(*pc)[i](av, 3) << endl;
        //cout << (*(*pc)[i])(av, 3) << " : " << *(*(*pc)[i])(av, 3) << endl;
    }
    
    /* 重点！！
     pa 和 &pa 值相同，都为第一个元素的地址，但类型不同
     &pa[0](pa的值) 单个指针地址
     &pa 整个数组地址
     pa + 1 为下一个元素的地址
     &pa + 1为整个数组后的地址
     
     因为&pa为地址，因此要获取第一个元素的值 需要两次解除引用
     */
    if(pa == &pa[0]){
        cout << "True" << endl;
    }
    if(*pa == **&pa){
        cout << "True" << endl;
    }
    if(*pa == pa[0]){
        cout << "True" << endl;
    }
    
    /*
     利用别名简化上述
     typedef
     */
    typedef const double * (*p_fun)(const double *, int);
    p_fun m1 = f1;
    
    cout << "\nUsing typedef to functions:\n";
    cout << "Address Value\n";
    cout << m1(av, 3) << " : " << *m1(av, 3) << endl;
    
    return 0;
}

void said_hi(){
    std::cout << "Hello, World!\n";
}

const double * f1(const double *ar, int n){
    return ar;
}

const double * f2(const double ar[], int n){
    return ar + 1;
}

const double * f3(const double ar[], int n){
    return ar + 2;
}
