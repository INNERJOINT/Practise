//
//  apple.hpp
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#ifndef apple_hpp
#define apple_hpp

#include <stdio.h>

class Apple{
public:
    enum{
        APPLE_COLOR_RED,
        APPLE_COLOR_BLUE,
        APPLE_COLOR_GREEN,
    };
    
    Apple();
    int GetColor(void);
    void SetColor(int color);
private:
    int m_nColor;
};

#endif /* apple_hpp */

