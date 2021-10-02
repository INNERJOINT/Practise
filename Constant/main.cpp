//
//  main.cpp
//  Constant
//
//  Created by Yukun on 2021/9/3.
//

#include <iostream>

/*
 C++中的变量作为用于替换#define而出现
 因此，const定义的常量编译器希望程序员给出一个明确的值并参与到编译中
 
 */

/*
 常量成员函数
 在一个类中，任何不会修改数据成员的函数都应该声明为const类型。
 */
class Stack {
private:
    int m_num;
    int m_data[100];
    const int n_num;
public:
    Stack(int m_num):n_num(40){
        this->m_num = m_num;
    }
    Stack():n_num(50){}
    void Push(int elem);
    void Pop(void);
    int GetCount(void);
    int GetCount(void) const;
};
int Stack::GetCount() const{
    //++m_num; 不允许修改数据成员
    //Pop();
    return 0;
}

//重载
int Stack::GetCount(){
    return m_num;
}



int main(int argc, const char * argv[]) {
    using namespace std;
    
    /*
     引用 声明了之后不能改变
     实际上是 int * const pr = &rats 的伪装表示，地址相同，标识符不同
     1. 引用初始化后不可变 指针可变
     1. 引用不存在const 指针可为const指针（常指针） ++ & * 都可以作为变量的描述符 解析从变量名向左侧开始解析
                                              ++ 因此，const * 表示该指针指向一个常量， * const表示该指针为常量
     */
    const int ival = 1024;
    const int &refVal = ival;
    //int &ref2 = ival; refVal为ival别名，均为const常量
    int i = 42;
    const int &r = 42;
    const int &r2 = r + i;//合法 42 + 42
    cout << r2 << endl;
    
    double dval = 3.14;
    const int &ri = dval;//隐式转换
    //int &rd = dval;非const引用只能绑定到类型相同的变量
    double &rd = dval;
    cout << ri << endl;
    
    //const int *pci = new const int[100]; const动态数组必须提供初始化
    const int *pci_a = new int[100]();
    //pci_a[1] = 9;
    const int *pci_b = new const int[100]{10,20,30};
    
    //修改const常量的方法，通过另外的指针修改
    //const int *cptr; 如果在const指针初始化时不指定地址则会随机地址
    const int *cptr = new int();
    int *tr = (int*)cptr;
    cout << "修改前：" << *cptr << endl;
    *tr = 5;
    cout << "修改后：" << *cptr << endl;
    
    /*
     const指针的本质
     1. const double *ptr 本身ptr不是const，只是限定了ptr所指向的变量不能修改
     2. const double * const ptr ptr时常指针，所指向的地址不能修改。
     */
    const double pi = 3.14;
    const double lang = 6.12;
    //double *pitr = &pi; const常量必须用const指针
    const double *const pitr = &pi;
    //pitr = &lang;错误
    cout << *pitr << endl;
    
    /*
     常成员函数
     */
    Stack s1(10);
    cout << s1.GetCount() << endl;
    const Stack s2(20);
    cout << s2.GetCount() << endl;
    
    return 0;
}
