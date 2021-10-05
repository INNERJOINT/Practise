//
//  String.hpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class String{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const { return len;}
    
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String &st);
    friend istream & operator>>(istream & is, String &st);
    
    static int HowMany();
};

#endif /* String_hpp */
