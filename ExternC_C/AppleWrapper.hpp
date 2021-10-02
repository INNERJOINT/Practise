//
//  AppleWrapper.hpp
//  ExternC_C
//
//  Created by Yukun on 2021/9/1.
//

#ifndef AppleWrapper_hpp
#define AppleWrapper_hpp

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct tagApple;
struct tagApple* GetInstance(void);
void ReleaseInstance(struct tagApple **ppInstance);
void SetColor(struct tagApple *pApple, int color);
int GetColor(struct tagApple *pApple);


#ifdef __cplusplus
};
#endif
#endif /* AppleWrapper_hpp */
