//
//  main.cpp
//  CXX11
//
//  Created by Yukun on 2021/9/10.
//

#include <iostream>
#include <memory>
#include <string>
#include "Circle.cpp"
#include "Useless.hpp"
#include "inlineNamespace.hpp"
#include "enumclass.hpp"

constexpr int factorial(int n){
    return n > 0 ? n * factorial(n - 1) : 1;
}
constexpr int fib(int n)
{
  if (n <= 0) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}
enum FIB_ENUM {
  a = fib(5),
  b = fib(10),
  c = fib(20),
  dummy = fib(0)
};

void deleteInt(int *p){
    delete []p;
}

/*
 后置类型
 auto做占位符
 */
double h(int x, float y);
template <class T1, class T2>
auto gt(T1 x1, T2 x2) -> decltype(x1 + x2);

int main(int argc, const char * argv[]) {
    using namespace std;
    
    /*
     constexpr 编译时常量
     和内联不同，可以递归
     1. 只能有一个return语句
     2. 只能调用constexpr函数
     3. 只能使用constexpr变量
     */
//     constexpr Circle c(0, 0, 10.0);
//     constexpr double area = c.getArea();
//    int n = 10;
//    constexpr int f = factorial(n);
    FIB_ENUM my_fib = a;
    printf("%d %d %d\n", my_fib, FIB_ENUM::b, FIB_ENUM::c);
    
    
    /*
     智能指针 引用计数器 (auto_ptr，在c++11中弃用）
     1. shared_ptr
     2. unique_ptr
     3. weak_ptr
     */
    shared_ptr<int> p1;
    shared_ptr<int> p2(nullptr);
    shared_ptr<int> p3(new int(10));
    shared_ptr<int> p4 = make_shared<int>(10);
    shared_ptr<int> p5(p3);//拷贝构造函数       p5和p3指向同一块内存，引用计数器加1
    shared_ptr<int> p6(move(p4));//移动构造函数 p6获得p4内存 p4变成空智能指针
    
    cout << p5.use_count() << endl;//查看指向同一内存的智能指针个数
    cout << *p5 << endl;
    p3.reset();
    if (p3) {
        cout << "p3 不为空" << endl;
    }
    else {
        cout << "p3 为空" << endl;
    }
    cout << *p5 << endl;
    cout << p5.use_count() << endl;//查看指向同一内存的智能指针个数
    
    int *ptr = new int;
    shared_ptr<int> p7(ptr);
//    shared_ptr<int> p8(ptr);
    
    //释放规则
    shared_ptr<int> t1(new int[10], default_delete<int[]>());//default_delete
    shared_ptr<int> t2(new int[10], deleteInt);//自定义释放规则
    
    /*
     auto_ptr 和 unique_ptr
     建立所有权
     */
    auto_ptr<string> film[4] =
    {
        auto_ptr<string> (new string("One")),
        auto_ptr<string> (new string("Two")),
        auto_ptr<string> (new string("Three")),
        auto_ptr<string> (new string("Four")),
    };
    auto_ptr<string> pwin;
    pwin = film[2];// 丢失film[2]的所有权
//    for (int i = 0; i < 5; i++) {
//        cout << *film[i] << endl;
//    }
    
    unique_ptr<string> movie[4] =
    {
        auto_ptr<string> (new string("One")),
        auto_ptr<string> (new string("Two")),
        auto_ptr<string> (new string("Three")),
        auto_ptr<string> (new string("Four")),
    };
    unique_ptr<string> pwin2;
    //pwin = film[2];// unique_ptr将编译报错
    pwin2 = move(movie[2]);//不报错 但所有权转移
//    for (int i = 0; i < 4; i++) {
//        cout << *movie[i] << endl;
//    }
    
    //shared_ptr<string> pp(pwin2);
    shared_ptr<string> pp(unique_ptr<string> pwin3);//shared_ptr通过显式构造函数将右值unique_ptr转换为shared_ptr
    cout << endl;
    
    /*
     移动语义和右值引用
     语义移动：将源对象的所有权转移
     右值引用的意义：减少使用临时变量的频率
     */
    Useless one (10, 'x');
    Useless two = one;// one是左值
    Useless three (20, 'o');
    Useless four (one + three);// one + three 是右值
    cout << "object one : ";
    one.ShowData();
    cout << "object two : ";
    two.ShowData();
    cout << "object three : ";
    three.ShowData();
    cout << "object four : ";
    four.ShowData();
    
    cout << "three = one\n";
    //three = static_cast<Useless &&>(one);//强制类型转换为右值引用
    three = one;
    cout << "now object three = ";
    three.ShowData();
    cout << "and object one = ";
    one.ShowData();
    cout << "four = one + two\n";
    four = one + two;//自动移动赋值
    cout << "now object four = ";
    four.ShowData();
    cout << "four = move(one)\n";
    four = std::move(one);//强制移动赋值
    cout << "now object four = ";
    four.ShowData();
    cout << "and object one = ";
    //one.ShowData();//报错，为空
    cout << endl;
    
    /*
     decltype
     1. decltype用途：
        template中 void ft(T1 x,T2 y){ ?type? xpy = x + y;}
        上述xpy的类型难以确定
        修复方法：
        void ft(T1 x,T2 y){ decltype(x+y) xpy = x + y;}
     
     2. decltype 核对表流程
        1. 第一步， 没有括号括起来的标识符 double x;decltype(x) w; w为double
        2. 第二步， expression为一函数调用，则为返回值类型 int ft(); decltype(ft()) w; w为int
        3. 第三步， expression为左值，为类型的引用，例如括号括起来的标识符 double x;decltype((x)) w; w为double & (括号不会改变表达式的值和左值性）
        4. 第四步， 上述步骤都不满足时，与expression表达式的类型相同 double &x, &y; decltype(x+y) w; w为double
     */
    double x = 2.42;
    decltype(x) w1;
    decltype((x)) w2 = x;
    
    
    
    /*
     inline namespace
     */
    cout << "内联命名空间：\n";
    using namespace Mine;
    V99::f(1);//调用V99新版本的f
    V98::f(1);//调用V98版本的f
    f(1);//调用Mine命名空间下的默认版本，即V99
    cout << endl;
    
    /*
     enum clas 枚举类
     1. 强类型 具有类域
     2. 可以前向声明 由于传统枚举的底层数据类型不能确定，因此不能像枚举类一样使用前向声明
     enum Alert//传统枚举
     {
         green, yellow, el  ection, red
     };
     enum class Color
     {
         red, blue
     };
     enum class TrafficLight
     {
         red, green, yellow
     };
     */
    //Alert a = 7;         //传统枚举 Alert不是强类型的 a没有数据类型
    //Color c = 7;         //枚举类   缺少int 到 Color的隐式转换
    int a2 = red;          //传统枚举 Alert隐式转化为int
    //int a5 = Color::blue;//枚举类。 缺少Color 到 int 的隐式转换
    Color a6 = Color::blue;
    cout << sizeof(a6) << endl;
    cout << endl;
    
    
    return 0;
}


