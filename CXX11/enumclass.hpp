//
//  enumclass.hpp
//  CXX11
//
//  Created by Yukun on 2021/9/13.
//

#ifndef enumclass_hpp
#define enumclass_hpp

#include <stdio.h>

enum Alert//传统枚举
{
    green, yellow, election, red
};
enum class Color :char//紧凑表示，默认情况下为int
{
    red, blue
};
enum class TrafficLight
{
    red, green, yellow
};

//前向声明
enum class Color_code : char;     // (前向) 声明
void foobar(Color_code* p);   // 使用
// ...
// 定义
enum class Color_code : char { red, yellow, green, blue };
#endif /* enumclass_hpp */
