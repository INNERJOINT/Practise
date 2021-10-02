//
//  main.cpp
//  ExternC
//
//  Created by Yukun on 2021/9/1.
//

#include <iostream>

/*
 C++ 调用 C
 
 表示采用C的符号表示，按照C的方式来封装接口
 例如 C++中函数重载可能表示成 _foo_float()
 C中则是_foo
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "cHeader.h"

#ifdef __cplusplus
}
#endif

int main(int argc, const char * argv[]) {
    
    print(3);//调用C中的print
    
    return 0;
}
