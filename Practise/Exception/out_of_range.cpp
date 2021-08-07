//
//  out_of_range.cpp
//  Practise
//
//  Created by Yukun on 2021/8/7.
//

#include "out_of_range.hpp"
#include <iostream>
#include <exception>

struct MyException : public std::exception {
    const char * what() const throw() {}
};
