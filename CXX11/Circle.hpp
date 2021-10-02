//
//  Circle.hpp
//  CXX11
//
//  Created by Yukun on 2021/9/10.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>

/*
 常量表达式
 */

//class Circle{
//public:
//    constexpr Circle(int x, int y, int radius) : _x(x), _y(y), _radius(radius) {}
//    constexpr double getArea() {
////        std::cout << "getArea()";
//        return _radius * _radius * 3.14;
//    }
//
//
//private:
//    int _x;
//    int _y;
//    double _radius;
//};

class Circle
{
    public:
    constexpr Circle (int x, int y, int radius) : _x( x ), _y( y ), _radius( radius ) {}
    constexpr double getArea () {
        return _radius * _radius * 3.1415926;
    }
private:
    int _x;
    int _y;
    int _radius;
};
#endif /* Circle_hpp */
