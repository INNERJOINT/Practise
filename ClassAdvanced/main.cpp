//
//  main.cpp
//  ClassAdvanced
//
//  Created by Yukun on 2021/10/4.
//

#include <iostream>
#include "StringBad.hpp"
#include "String.hpp"

using namespace std;

void callme1(StringBad &);
/*
 这里由于调用了复制构造函数生成临时变量
 临时变量释放时释放了内存，导致后续headline2释放时出错
 */
void callme2(StringBad);

int main(int argc, const char * argv[]) {
    
    /*
     要重现问题，注释stringbad中的复制构造函数和赋值运算符重载
     下述存在的问题（浅复制导致的问题）
     1. 由于存在一个静态类成员变量，相关复制构造函数使用默认的复制构造函数导致num_strings没有更新
     2. 默认构造函数将同一内存的指针直接复制到新的对象，导致同一内存块被释放两次导致报错
     */
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
        cout << "headline1: " << headline1 << endl << endl;
    }
    
    /*
     改进后的String类
     */
    {
        const int ArSize = 10;
        const int MaxLen = 81;
        String name;
        cout << "Hi, what is your name?\n >>";
        cin >> name;
        
        cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
        String sayings[ArSize];
        char temp[MaxLen];
        int i;
        for (i = 0; i < ArSize; i++) {
            cout << i + 1 << ": ";
            cin.get(temp, MaxLen);
            while (cin && cin.get() != '\n') {
                continue;
            }
            if(!cin || temp[0] == '\0')
                break;
            else
                sayings[i] = temp;
        }
        int total = i;
        
        if(total){
            cout << "Here are your sayings:\n";
            for (i = 0; i < total; i++) {
                cout << sayings[i][0] << ": " << sayings[i] << endl;
            }
            int shortest = 0;
            int longest = 0;
            for (i = 1; i < total; i++) {
                if(sayings[i].length() < sayings[shortest].length()) shortest = i;
                if(sayings[i].length() > sayings[longest].length()) longest = i;
            }
            cout << "Shortest sayings:\n" << sayings[shortest] << endl;
            cout << "Longest sayings:\n" << sayings[longest] << endl;
            cout << "This program used " << String::HowMany() << " String objects.Bye\n";
        }else{
            cout << "No input!Bye.\n";
        }
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
