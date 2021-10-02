//
//  class.hpp
//  Templated
//
//  Created by Yukun on 2021/9/18.
//

#ifndef class_hpp
#define class_hpp

#include <stdio.h>
#include <vector>

template <class T>
class Stack {
private:
    std::vector<T> elems;

public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
        return elems.empty();
    }
};
#endif /* class_hpp */
