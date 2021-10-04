//
//  StringBad.hpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#ifndef StringBad_hpp
#define StringBad_hpp

#include <stdio.h>
#include <iostream>

class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad();
    ~StringBad();
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif /* StringBad_hpp */
