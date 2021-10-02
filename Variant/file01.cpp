//
//  file01.cpp
//  Variant
//
//  Created by Yukun on 2021/9/3.
//

#include <stdio.h>
#include "config.h"
#include <iostream>

//声明变量 extern 可加可不加
extern int cats = 20;
int dogs = 22;
int fleas = 30;

/*
 使用外链接性const的方法：
 1.在一个公有的头文件中定义，由于const具有内链接性，因此不会命名冲突，每个文件都有一份const变量的备份
 2.在源文件添加extern覆盖内链接性
 */
extern const int h = 44;

//修改const变量的方法
//猜测可能是const变量会长期保存在缓存中
void c(){
    const int a = 7;
    int  *p = (int*)&a;
    *p = 8;
    std::cout<<a; // a = 7
}

void b(){
    volatile const int  a = 7;
    int  *p = (int*)&a;
    *p = 8;
    std::cout<<a; // a = 8
}

void printConstAddr(){
    using std::cout;
    cout << "const variant fly in file01 addr: " << &fly << std::endl;
}

