//
//  Base.hpp
//  Virtual
//
//  Created by Yukun on 2021/9/8.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>

class Base{
public:
    Base();
    virtual ~Base();
    Base(int i);
private:
    int BaseI;
};

#endif /* Base_hpp */
