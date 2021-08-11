//
//  template.cpp
//  Practise
//
//  Created by Yukun on 2021/8/7.
//

#include "template.hpp"
#include "../Exception/out_of_range.hpp"
#include <iostream>
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

template <class T>
void Stack<T>::push (T const& elem) {
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop () {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop() empty stack");
    }
    elems.pop_back();
}

template <typename T>
T Max (T const& a, T const& b) {
    return a < b ? b : a;
}

int main(){
    int i = 39;
    int j = 20;
    std::cout << "Max(i, j): " << Max(i,j) << std::endl;
    
    return 0;
}
