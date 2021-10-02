//
//  visibility.hpp
//  _Attribute
//
//  Created by Yukun on 2021/9/10.
//

#ifndef visibility_hpp
#define visibility_hpp

#include <stdio.h>
#include <stdlib.h>

__attribute((visibility("hidden"))) inline void not_hidden(){
    printf("exported symbol\n");
}

inline void is_hidden(){
    printf("hidden one.\n");
}


#endif /* visibility_hpp */
