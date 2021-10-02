//
//  apple.cpp
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#include "apple.hpp"

Apple::Apple() : m_nColor(APPLE_COLOR_RED){
    
}

void Apple::SetColor(int color){
    m_nColor = color;
}

int Apple::GetColor(){
    return m_nColor;
}
