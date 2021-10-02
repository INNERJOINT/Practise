//
//  main.cpp
//  Define
//
//  Created by Yukun on 2021/9/4.
//

#include <iostream>

/*
 预处理运算符
 1. \ 宏延续运算符
 2. # 字符串常量化运算符
 3. ## 标记粘贴运算符
 4. ... __VA_ARGS__ 变参
 */
#define _INT int
#define Conn(x, y) x##y
#define ToString(x) #x
#define PR(...) printf(__VA_ARGS__)

#define MAX(a, b) a > b ? a : b

#define _CONFIG_FIB(type) \
type fib_##type(type count){\
    if (count <= 0) return 0;\
    else if(0 < count <= 1) return count;\
    else return fib_##type(count - 1) + fib_##type(count - 2);\
}\

_CONFIG_FIB(int)
_CONFIG_FIB(double)

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int i = MAX(5, 6);
    cout << i << endl;
    //预处理连接
    PR("hoer%s\n","erer");
    
    //
    cout << fib_int(5) << endl;//0 + 1 + 1 + 2 + 3
    cout << fib_double(7.5) << endl;
    return 0;
}
