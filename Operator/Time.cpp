//
//  Time.cpp
//  Operator
//
//  Created by Yukun on 2021/9/7.
//

#include "Time.hpp"
#include <iostream>

Time::Time(){
    hours = minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::AddHr(int h){
    hours += h;
}

void Time::AddMin(int m){
    minutes += m;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time & t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator+(const Time & t) const{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

//友元函数
Time operator*(double n, const Time &t) {
    Time result;
    long long totalminutes = t.hours * n * 60 + t.minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

Time Time::operator*(double n) const{
    Time result;
    long long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

void Time::Show() const{
    std::cout << hours << " hours, " << minutes << " minutes\n";
}

void Time::operator<<(std::ostream &os)const{
    os << hours << " hours, " << minutes << " minutes\n";
}

std::ostream& operator<<(std::ostream &os, const Time &t){
    os << t.hours << " hours, " << t.minutes << " minutes\n";
    return os;
}
