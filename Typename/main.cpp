//
//  main.cpp
//  Typename
//
//  Created by Yukun on 2021/9/11.
//

#include <iostream>


struct ContainsAType {
    struct iterator {};
};

/*
 引入typename的必要性
 用于指出模板声明中的非独立名称是类型名
 如果不定义则会认为T::iterator 乘以 pr
 1. T::iterator只有在实例化时才能知道是哪种类型
    类型可能有：
    1. 静态数据成员 static int iterator;
    2. 静态成员函数 static int iterator();
    3. 嵌套类型    struct iterator{}
 */
template <typename T>
void foo() {
    typename T::iterator * pr;
}

template <class T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    
    foo<ContainsAType>();
    compare(4, 5);
    
    return 0;
}
