//
//  main.cpp
//  EnvironmentTest
//
//  Created by Yukun on 2021/9/3.
//

#include <iostream>

/*
 不同编译器的宏定义
 
 Borland    __BORLANDC__

 Codeplay VectorC   __VECTORC__

 Digital Mars   __DMC__

 Gnu         __GNUC__

 Intel       __INTEL_COMPILER

 Microsoft   _MSC_VER

 Pathscale   __PATHSCALE__

 Symantec    __SYMANTECC__

 Watcom      __WATCOMC__
 */
void test(void);

int main(int argc, const char * argv[]) {
    test();
    return 0;
}

void test(void){
    int len = sizeof(int) * 8;
    printf("sizeof(int) = %d\n", len);
    
    len = sizeof(int *) * 8;
    printf("sizeof(int *) = %d\n", len);
    
#ifdef _MSC_VER
    printf("_MSC_VER is defined\n");
#endif
    
#ifdef __GNUC__
    printf("__GNUC__ is defined\n");
#endif
    
#ifdef __INTEL__
    printf("__INTEL__ is defined\n");
#endif
    
#ifdef __i386__
    printf("__i386__ is defined\n");
#endif
    
#ifdef __x86_64__
    printf("__x86_64__ is defined\n");
#endif
    
#ifdef _WIN32
    printf("_WIN32 is defined\n");
#endif
    
#ifdef _WIN64
    printf("_WIN64 is defined\n");
#endif
    
#ifdef __linux__
    printf("__linux__ is defined\n");
#endif
    
#ifdef __LP64__
    printf("__LP64__ is defined\n");
#endif
    
#ifdef __amd64
    printf("__amd64 is defined\n");
#endif
}
