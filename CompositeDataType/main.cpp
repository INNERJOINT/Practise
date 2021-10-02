//
//  main.cpp
//  CompositeDataType
//
//  Created by Yukun on 2021/8/26.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    using namespace std;
    
    /*
     拼接字符串
     */
    cout << "I'd give my right to be "  "a greate violinist.\n";
    cout << "I'd give my right to be "
    "a greate violinist.\n";
    
    /*
     字符串输入
     */
    const int ArSize = 20;
    char name1[ArSize];
    char name2[ArSize];
    char dessert1[ArSize];
    char dessert2[ArSize];
    
    //getline 忽视行间空格和换行
    cout << "Enter your name1:\n ";
    cin.getline(name1, ArSize);
    cout << "Enter your dessert1:\n ";
    cin.getline(dessert1, ArSize);
    cout << "I have some delicious " << dessert1 << " for you, " << name1 << endl;

    //get    忽视行间空格，但不忽视换行
    cout << "Enter your name2:\n ";
    cin.get(name2, ArSize);
    cout << "Enter your dessert2:\n ";
    cin.get(dessert2, ArSize).get();
    cout << "I have some delicious " << dessert2 << " for you, " << name2 << endl;
    
    // cin>> 输入存在的问题
    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();//cin后留下换行符导致后续无法正确读取。
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    
    
    return 0;
}
