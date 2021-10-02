//
//  main.cpp
//  Exception
//
//  Created by Yukun on 2021/8/7.
//

#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main(){
    double x, y, z;
    
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y) {
        z = hmean(x, y);
        std::cout << "harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b){
    if (a == -b){
        std::cout << "unteable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
