//
//  AppleWrapper.cpp
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#include "AppleWrapper.hpp"
#include "apple.hpp"

#ifdef __cplusplus
extern "C" {
#endif

struct tagApple{
    Apple apple;
};

struct tagApple* GetInstance(void){
    return new tagApple;
}

void ReleaseInstance(tagApple **ppInstance){
    delete *ppInstance;
    
}

void SetColor(tagApple *pApple, int color){
    pApple->apple.SetColor(color);
}

int GetColor(tagApple *pApple){
    return pApple->apple.GetColor();
}

#ifdef __cplusplus
};
#endif
