//
//  file02.cpp
//  Variant
//
//  Created by Yukun on 2021/9/3.
//

#include <stdio.h>
#include <iostream>
#include "config.h"

extern int cats;
extern int dogs;

void printConstAddr2(){
    using std::cout;
    cout << "const variant fly in file02 addr: " << &fly << std::endl;
}
