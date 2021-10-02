//
//  cppHeader.cpp
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#include "cppHeader.hpp"
#include <iostream>

/*
 标准做法是将extern C用预处理命令#ifdef __cplusplus包裹起来
 本例中，如果没有包起来在main中include头文件会报错
 原因应该是在c文件中会包含该头文件，而C编译器不能识别extern C 因此在头文件中需要添加预处理命令
 */
//#ifdef __cplusplus
extern "C" {
//#endif
using namespace std;

void print(int i){
    cout << "cppHeader " << i << endl;
}

//#ifdef __cplusplus
};
//#endif
