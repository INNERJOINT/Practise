//
//  StringBad.cpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#include "StringBad.hpp"
using namespace std;

int StringBad::num_strings = 0;

StringBad::StringBad(const StringBad & st){
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad & StringBad::operator=(const StringBad &st){
    if(this == &st) return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

StringBad::StringBad(const char * s){
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad(){
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::~StringBad(){
    cout << "\"" << str << "\" object delete, ";
    num_strings--;
    cout << num_strings << " lefe\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st){
    os << st.str;
    return os;
}
