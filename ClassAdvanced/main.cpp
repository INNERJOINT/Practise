//
//  main.cpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#include <iostream>
#include "StringBad.hpp"

using namespace std;

void callme1(StringBad &);
void callme2(StringBad);

int main(int argc, const char * argv[]) {
    
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalk at Midnight");
        StringBad headline2("Letturce Prey");
        StringBad sport("Spinach Leavs Bowl for Dollars");
        cout << "headline1:" << headline1 << endl;
        cout << "headline2:" << headline2 << endl;
        cout << "sport:" << sport << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sport;
        cout << "salior: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "headline1: " << headline1 << endl;
        
    }
    
    return 0;
}

void callme1(StringBad & rsb){
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb){
    cout << "String passed by value:\n";
    cout << "   \"" << sb << "\"\n";
}
