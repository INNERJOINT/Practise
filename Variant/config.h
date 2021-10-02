//
//  config.h
//  Practise
//
//  Created by Yukun on 2021/9/3.
//

#ifndef config_h
#define config_h

/*
 ！！！为什么const是内链接性？
    由于const对象可用作C++中的编译时值，因此此功能敦促程序员为每个const提供显式的初始化程序值。
    此功能允许用户将const对象放入许多编译单元中包含的头文件中。 因此，如果为外链接性，则将不能放入头文件中。
 
 
 可以定义在头文件的情况
 1. const变量
 2. inline函数
 两者都有着特殊的链接性（内部链接性）
 */

//全局变量的使用注意：
//1.因最好用const修饰
//2.如果是指针，最好const修饰避免指针被修改
const char* const months[12] = {
    "January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October",
    "November", "December"
};

//定义在头文件内的const常量在包含到不同文件中时会产生多个副本,因此同样的常量在不同文件中地址是不一样的
const int fly = 59;

inline void a(){
    return ;
}
#endif /* config_h */
