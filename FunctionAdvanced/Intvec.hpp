//
//  Intvec.hpp
//  FunctionAdvanced
//
//  Created by Yukun on 2021/9/9.
//

#ifndef Intvec_hpp
#define Intvec_hpp

#include <stdio.h>
#include <iostream>

class Intvec{
public:
    explicit Intvec(size_t num = 0)
    : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
    }
    
    ~Intvec()
    {
        log("destructor");
        if (m_data) {
            delete [] m_data;
            m_data = 0;
        }
    }
    
    //拷贝构造器
    Intvec(const Intvec &other)
    : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");
        for (size_t i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    
    Intvec& operator=(const Intvec &other)
    {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }
    
//    //右值引用 &&
//    Intvec& operator=(Intvec &&other)
//    {
//        log("move assignment operator");
//        std::swap(m_size, other.m_size);
//        std::swap(m_data, other.m_data);
//        return *this;
//    }
    
private:
    void log(const char *msg){
        std::cout << "[" << this << "]" << msg << "\n";
    }
    
    size_t m_size;
    int *m_data;
};

#endif /* Intvec_hpp */
