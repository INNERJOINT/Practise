//
//  String.cpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#include "String.hpp"

int String::num_strings = 0;

int String::HowMany(){
    return num_strings;
}

String::String(const char * s){
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String(){
    len = 0;
    str = new char[1];//与析构函数[]匹配
}

String::String(const String &);
String::~String();
int String::length() const { return len;}

String & String::operator=(const String &);
String & String::operator=(const char *);
char & String::operator[](int i);
const char & String::operator[](int i) const;

bool operator<(const String &st, const String &st2);
bool operator>(const String &st, const String &st2);
bool operator==(const String &st, const String &st2);
ostream & operator<<(ostream & os, const String &st2);
ostream & operator<<(ostream & os, const String &st2);
