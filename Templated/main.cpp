//
//  template.cpp
//  Practise
//
//  Created by Yukun on 2021/8/7.
//

#include <iostream>

template <typename T>
void Swap(T &a, T &b);

/*
 优先级
 1. 非模版函数
 2. 显式具体化模版函数
 3. 模版函数
 
 may('B');
 候选函数：
 1. void may(int);
 2. float may(float, float = 3);
 3. void may(char);
 4. char* may(const char *);
 5. char may(const char &);
 6. template<class T> void may(const T &);
 7. template<class T> void may(T *);
 
 1⃣️ 特征标 4和7 不存在证书类型到char *的隐式转换
 */

template <typename T>
void Swap(T *a, T *b, int n);
void Show(int a[]);
const int Lim = 8;

/*
 显式实例化 和 隐式实例化
 */
template <typename T>
T Add(T a, T b)
{
    return a + b;
}

/*
 显式具体化 不要使用模版生成函数定义
 */
struct job{
    char name[40];
    double salary;
    int floor;
};
template<> void Swap<job>(job &j1, job &j2);
void Show(job &j);

/*
 完全匹配和最佳匹配
 */
struct blot {
    int a;
    char b[10];
};
//void recycle(blot);
//void recycle(const blot);
void recycle(blot &){
    std::cout << "recycle blot &" << std::endl;
}
void recycle(const blot &){
    std::cout << "recycle const blot &" << std::endl;
}
template <class Type> void recycle2(Type t){
    std::cout << "recycle template" << std::endl;
}
template <> void recycle2<blot> (blot t){
    std::cout << "recycle specialization template" << std::endl;
}
template <class Type> void recycle3(Type t){
    std::cout << "recycle template Type" << std::endl;
}
template <class Type> void recycle3(Type * t){
    std::cout << "recycle template Type *" << std::endl;
}

/*
 创建自定义选择
 */
template <class T>
T lesser(T a, T b){
    return a < b ? a : b;
}
int lesser(int a, int b){
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

/*
 后置类型
 */
template<typename T1, typename T2>
auto th(T1 x, T2 y) -> decltype(x + y);

int main(){
    using namespace std;
    
    /*
     完全匹配
     1.存在两个完全匹配的函数时的优先级
        1. const 实参与 const 形参优先匹配
        2. 非模版优先于模版
        3. 都是模版时，则寻找更“具体”的函数
     */
    //CV修饰符完全匹配的优先
    const blot ink = {25, "spots"};
    recycle(ink);
    blot unk = {24, "sbot"};
    recycle(unk);
    //非模版优先
    recycle2(ink);
    //模版匹配，以最具体为原则，指的是执行的转换最少
    recycle3(&ink);
    cout << endl;
    
    //模版的简单实用案例
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    cout << "Using complier-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j <<endl;
    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original array:\n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);
    cout << "Swapped array:\n";
    Show(d1);
    Show(d2);
    cout << endl;
    
    /*
     显式实例化 和 隐式实例化
     */
    int m = 6, n = 8;
    double x = 10.2;
    cout << Add(m, n) << endl;// 隐式实例化 通过参数int 实例化出Add(int,int)
    cout << Add<double>(m, x) << endl;//显式实例化 由于参数包括多个类型 无法自动确定实例化 通过显式实例化为Add（double,double)
    //Swap<double>(m, x);//无法通过显式实例化正常工作 实例化为Swap（double &,double &)  因为int m 无法赋值给double &
    
    /*
     显式具体化 explicit specialization
     如果没有自定义一个显式具体化的Swap函数，对于结构体，将直接交换结构体内的所有成员
    */
    job sue = {"sue", 7300.60, 7};
    job sidney = {"sidney", 2284.3, 9};
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);
    cout << endl;
    
    /*
     创建自定义选择
     */
    int m2 = 20;
    int n2 = -30;
    double x2 = 15.5;
    double y2 = 25.9;
    cout << lesser(m2, n2) << endl;//调用具体函数 返回绝对值小的
    cout << lesser(x2, y2) << endl;//调用模版函数
    cout << lesser<>(m2, n2) << endl;// <> 指定使用模版
    cout << lesser<int>(m2, n2) << endl;// 显式实例化
    
    return 0;
}

template <typename T>
void Swap(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

template <typename T>
void Swap(T *a, T *b, int n)
{
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<> void Swap(job &j1, job &j2)
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    using namespace std;
    cout << j.name << ": $" <<j.salary << " on floor " << j.floor << endl;
}

void Show(int a[]){
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[4] << "/";
    for (int i = 4; i < Lim; i++) {
        cout << a[i];
    }
    cout << endl;
}

