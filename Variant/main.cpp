//
//  main.cpp
//  Variant
//
//  Created by Yukun on 2021/9/3.
//

#include <iostream>
#include <new>
/*
 变量的描述
 1. 持续性
 2. 作用域 命名空间用于解决同一作用域下命名重复
 3. 链接性
 
    储存描述 持续性 作用域 链接性
 1. 自动     自动  代码块 无
 2. 寄存器   自动  代码块  无
 3. 静态，无链接 静态 代码块 无 {static int count;}
 4  静态，内链接 静态 文件  内 static
 5. 静态，外链接 静态 文件  外
 
 持续性拓展 线程 thread_local
 */


/*
 1. 自动存储
    1. 自动变量
    2. 寄存器变量 register(已经被淘汰，编译器对于变量已经有比较好的优化，会决定变量存放到缓冲和寄存器中）
        建议型关键字：register 和 inline 具体能不能成功取决于编译器，如果没能请求成功则会变成一个普通的自动变量
        不能对register取地址&,因为寄存器变量存放在寄存器中，取地址&只适用于存放于内存中的变量
      register 和 volatile
      1.volatile  变量必须保存在内存中，防止脏数据 （多线程中可能出现缓存和寄存器的情况导致获取到没有及时更新的脏数据）
      2.register  变量尽可能保存着寄存器中，可能不生效
 2. 静态存储
 */

/*
 引用file01.cpp的变量
 1.定义 Definition
 2.声明 Declaration
 */
extern int cats;
extern int dogs;
extern int fleas;
int hell;//静态,外链接
static int god;//静态，内链接
#include "config.h"
void strcount(const char * str);
extern void printConstAddr2();
extern void printConstAddr();


extern void printg();
int main(int argc, const char * argv[]) {
    using namespace std;
    
    //打印不同文件内同一常量地址
    printConstAddr();
    printConstAddr2();
    int w ;//自动变量，值随机
    register int count_fast = 5;
    volatile int count_slow = 6;//不进行优化，不存放到缓存，避免脏数据
    
    
    cout << "代码块自动变量，值随机： w : " << w << endl;
    cout << "寄存器变量，只能用于代码块内 : " << count_fast << endl;
    
    int fleas = 44;//局部变量隐藏全局变量
    cout << "file01.cpp : cats : " << cats << endl;
    cout << "file01.cpp : dogs : " << dogs << endl;
    cout << "file01.cpp : fleas : " << ::fleas << endl;// ::使用全局变量
    cout << "local : fleas : " << fleas << endl;
    cout << "config.h : const fly : " << fly << endl;
    
    /*
     变量无链接性
     strcount内的total变量使用static修饰
     */
    char input[10];
    char next;
    
    cout << "Enter a line:\n";
    cin.get(input, 10);
    while (cin) {
        cin.get(next);
        while (next != '\n') {
            cin.get(next);
        }//忽略10个字符后的字符串
        strcount(input);
        cout << "Enter next line (empty line to quit): \n";
        cin.get(input, 10);
    }
    
    /*
     mutal 允许修改const的结构或类变量
     */
    struct data{
        char name[30];
        mutable int access;
    };
    const data veep = {"Onimy", 2};
    veep.access = 1;
    
    /*
     new是一个运算符
     
     定位new运算符new() 需要inclue<new>
     存放到内存的指定位置中
     */
    struct chaff{
        int slag;
        char dross[20];
    };
    char buffer1[50];
    char buffer2[500];
    chaff *p1, *p2;
    int *p3, *p4;
    p1 = new chaff{1,"chaff single"};
    p3 = new int[20];
    //断点 调试查看buffer1和buffer2内容
    p2 = new(buffer1) chaff{2,"chaff single2"};
    p4 = new(buffer2) int[20]{60,61,62,63};//在buffer2中ascii编码为 < = > ?
    
    return 0;
}

void strcount(const char * str){
    using namespace std;
    static int total = 0;
    int count = 0;
    
    cout << "\"" << str << "\" contains ";
    while (*str++) {
        count++;
    }
    total += count;
    cout << count << " characters\n" << total << "characters total\n";
}
