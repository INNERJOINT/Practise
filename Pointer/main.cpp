//
//  main.cpp
//  Pointer
//
//  Created by Yukun on 2021/8/27.
//

#include <iostream>

char * getname();
int main(int argc, const char * argv[]) {
    
    using namespace std;
    
    int donuts = 6;
    int cookie = 5;
    double cups = 4.5;
    
    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    cout << "cookie value = " << cookie;
    cout << " and cookie address = " << &cookie << endl;
    
    //定义指针
    double*cups_ptr = &cups;
    *cups_ptr = 5.5;
    
    cout << "  cups value = " << cups << endl;
    
    //手动分配指针
    int * pt;
    pt = (int *)0x7ffeefbff3b8;
    *pt = 8;
    
    cout << "cookie value = " << cookie << endl;
    
    cout << "sizeof cookie = " << sizeof(cookie) << " , sizeof cookie_ptr = " << sizeof(pt) << endl;
    
    /*
     new 分配
     1. 声明变量存储在 栈 中
     2. new存储在 堆 中
     */
    int* pn = new int;
    *pn = 20;
    //int* pn = new int(20);
    
    cout << "new int: pn = " << *pn << endl << endl;
    
    /*
     delete 释放内存
     1. 只适用于new分配的内存
     2. 同一内存块不能delete两次
     3. delete空指针是安全的
     
     如果不delete释放内存，则可能导致内存泄漏
     
     内存泄露——失去对原本内存块的控制
     例子：
     int* pn;
     while (true) {
         pn = new int;
     }
     */
    delete pn;
    
    //指向同一内存块的指针
    int * ps = new int;
    int * pq = ps;
    delete pq;
    
    /*
     动态数组
     */
    double * p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[0] is " << p3[0] << " , p3[1] is " << p3[1] << endl;
    // 指针向后移动
    p3 = p3 + 1;
    cout << "Now p3[0] is " << p3[0] << " , p3[1] is " << p3[1] << endl << endl;
    // 指针往回移动
    // 以便能够正确的delete
    p3 = p3 - 1;
    delete [] p3;
    
    /*
     指针数组和数组指针
     []运算符优先级比*高
     1. 数组指针   short(*)[] 先声明为指针
     2. 指针数组   short * [] 先声明为数组
     */
    short tell[10]{1,2,3,4};
    cout << tell << endl;
    cout << &tell << endl;
    
    short *qas[10];
    qas[0] = new short(5);
    qas[1] = new short(6);
    qas[2] = new short(7);
    qas[3] = new short[3];//指针指向一个数组
    qas[3][0] = 8;
    qas[3][1] = 9;
    qas[3][2] = 10;
    short (*pas)[10] = &tell;
    
    cout << (*pas)[0] << endl;
    cout << (*pas)[1] << endl;
    cout << (*pas)[2] << endl;
    cout << *qas[0] << endl;
    cout << *qas[1] << endl;
    cout << *qas[2] << endl;
    cout << qas[3][0] << endl;//按数组名方式访问new数组
    cout << qas[3][1] << endl;
    cout << qas[3][2] << endl << endl;
    
    /*
     指针和字符串
     1. = 只是地址的复制
     2. strcpy 将字符串复制到另外一段内存块上
     */
    char animal[20] = "bear";
    const char * brid = "wren";
    char * cp;
    
    cout << animal << " and " << brid << endl;
    //cout << cp << endl;
    
    cout << "Enter a kind of animal: ";
    cin >> animal;
//    cin >> cp;
    
    cp = animal;
    cout << cp << "!\n";
    cout << "Before using strcpy():\n" ;
    cout << animal << " at " << (int*)animal << endl;
    cout << cp << " at " << (int*)cp << endl;
    
    cp = new char[strlen(animal) + 1];
    strcpy(cp, animal);
    cout << "After using strcpy():\n" ;
    cout << animal << " at " << (int*)animal << endl;
    cout << cp << " at " << (int*)cp << endl;
    delete [] cp;
    
    /*
     动态结构
     struct inflatable {
         char name[20];
         float volumn;
         double price;
     };
     inflatable *ss = new inflatable;
     
     ss为指向该结构的指针
     *ss是该结构，因此
     1. 指针访问结构的成员的两种方法
        1.1 (*ss).name
        1.2 ss->name
     */
    struct inflatable {
        char name[20];
        float volumn;
        double price;
    };
    
    inflatable *ss = new inflatable;
    cout << "Enter name of inflatable item: ";
    cin.get();//cin残留的换行符 或者 直接cin>>ss->name;
    cin.get(ss->name, 20);
    cout << "Enter volumn of inflatable item: ";
    cin >> ss->volumn;
    cout << "Enter price of inflatable item: ";
    cin >> (*ss).price;
    cout << "Name: " << (*ss).name << endl;
    cout << "Volumn: " << ss->volumn << endl;
    cout << "Price: " << (*ss).price << endl;
    delete ss;
    
//    /*
//     一种尝试节约内存的方法
//     */
//    char * name;
//
//    name = getname();
//    cout << name << " at " << (int*)name << endl;
//    delete name;
//
//    name = getname();
//    cout << name << " at " << (int*)name << endl;
//    delete name;
    
    /*
     类型组合
     */
    struct antarctica_years_end{
        int year;
    };
    
    antarctica_years_end s01, s02, s03;
    s01.year = 2000;
    s02.year = 2001;
    s03.year = 2002;
    const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
    const antarctica_years_end ** ppa = arp;
    auto ppb = arp;//自动判断
    
    cout << arp[1]->year << endl;//s02
    cout << (*ppa)->year << endl;//s01
    cout << (*(ppb+2))->year << endl;//s03
    
    /*
     数组的不安全性
     可能存在的越界问题
     */
    double a1[4] = {1.2, 2.4, 3};
    a1[-2] = 4.4;
    cout << a1[-2];
    
    return 0;
}

char * getname(){
    using namespace std;
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    
    return pn;
}
