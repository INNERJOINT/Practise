//
//  main.c
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#include <stdio.h>
#include "cppHeader.hpp"
#include "AppleWrapper.hpp"

/*
 直接调用（原理猜测参考如下）
 g++ -c apple.cpp //生成中间文件
 g++ -c apple.cpp  AppleWrapper.cpp //生成中间文件
 gcc test.c -o test AppleWrapper.o apple.o -lstdc++ //Xcode可能在编译过程中自动进行了这三个步骤
 
 只适合调用非成员函数
 由于C不存在类 当需要调用类的成员函数时 需要进行包装
 */
void print(int i);

int main(int argc, char** argv){
    
    print(3);
    
    struct tagApple * pApple;
    pApple = GetInstance();
    SetColor(pApple, 1);
    int color = GetColor(pApple);
    printf("color = %d\n", color);
    ReleaseInstance(&pApple);
    
    return 0;
}
