//
//  main.cpp
//  Namespace
//
//  Created by Yukun on 2021/8/9.
//

#include <iostream>
#include "namesp.hpp"

namespace Jill
{
    double bucket(double n);
    double fetch;
    struct Hill;
}
namespace Jill
{
    char * goose(const char *);
}

namespace Jack
{
    namespace Marry
    {
        using Jill::fetch;
        using std::cin;
        using std::cout;
        using std::endl;
        int flame;
    }
    double fetch;
}

/*
 名称空间的别名
 */
namespace husband = Jack;
namespace wife = Jack::Marry;

/*
 未命名空间，只能在声明区域内使用
 和静态全局作用一样
 static int counts;
 */
namespace
{
    int counts;
}

void other();
char fetch = 'c';

//int main() {
//    using namespace Jill;
//    double fetch = 3.14;
//
//    /*
//     using编译命令不会覆盖已有变量
//     using声明会覆盖已有变量
//     using Jill::fetch;
//     double fetch;//ERROR!
//     */
//
//    std::cin >> fetch;
//    //std::cin >> ::fetch;
//    std::cin >> Jill::fetch;
//
//    std::cout << fetch << std::endl;/* 局部名称空间 */
//    std::cout << ::fetch << std::endl;/* 全局名称空间 */
//    std::cout << Jill::fetch << std::endl;/* 隐藏名称空间 */
//    other();
//    return 0;
//}

//int main() {
//    using namespace Jack::Marry;
//    cin >> Jack::Marry::fetch;
//    counts = 11;
//    other();
//    return 0;
//}

void other() {
    std::cout << Jill::fetch << std::endl;
    std::cout << counts << std::endl;
}


namespace name_ADL
{
    struct St{};
    void ADLfunction(St s){}
}
/*
 ADL特性（Argument-Dependent name Lookup)
 参数关联名称查找 当编译器在名字空间找不到一个函数的定义时，就会到这个函数的参数所在的命名空间去查找
 */
int main(){

    name_ADL::St st;
    ADLfunction(st);//查找name_ADL空间内的方法
    return 0;
}

