//
//  class.cpp
//  Templated
//
//  Created by Yukun on 2021/9/18.
//

#include "class.hpp"
#include <iostream>

template <class T>
void Stack<T>::push (T const& elem) {
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop () {
    if (elems.empty()) {
//        throw out_of_range("Stack<>::pop() empty stack");
        std::cout << "Stack<>::pop() empty stack" << std::endl;
        return;
    }
    elems.pop_back();
}
