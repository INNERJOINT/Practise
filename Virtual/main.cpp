//
//  main.cpp
//  Virtual
//
//  Created by Yukun on 2021/9/8.
//

#include <iostream>
#include "Base.hpp"
#include "Drive.hpp"

void nvs_get_blob(int * length){
    (*length) = 1;
}

int main(int argc, const char * argv[]) {
    
    using namespace std;
    
    int a = 10;
    nvs_get_blob(&a);
    
    return 0;
}
