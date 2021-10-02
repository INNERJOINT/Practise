//
//  main.cpp
//  Class
//
//  Created by Yukun on 2021/9/5.
//

#include <iostream>
#include "Stock.hpp"

int main(int argc, const char * argv[]) {
    using namespace std;
//    Stock s1;
//    s1.acquire("NanoSmart", 20, 12.5);
//    s1.show();
//    s1.buy(15, 18.125);
//    s1.show();
//    s1.sell(400, 20.0);
//    s1.show();
//    s1.buy(300000, 40.125);
//    s1.show();
//    s1.sell(300000, 0.125);
//    s1.show();
//    std::cout << std::endl;
    
    /*
     通常使用初始化的方式设置对象的值效率更高，因为赋值会产生一个临时对象
     
     1.对象初始化，可能不会产生一个临时对象并销毁
     2.对象复制，两个内存块之间的复制
     3.已存在的对象进行重新赋值，会产生一个临时对象并销毁
     */
    Stock stock1  ("NanoSmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);//不同编译器可能存在另外的方法： 创建一个临时对象并复制到stock2中，后并销毁临时对象
    stock2.show();
    
    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;//将stock1内存块复制到stock2内存块上，不调用析构函数
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();
    
    cout << "Using a construtor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);//stock1已经初始化，会产生一个临时对象
    stock1.show();
    
    //初始化列表的方式
    Stock hot_tip = {"Derver", 100, 45.0};
    Stock jock {"SPort", 200, 50.0};
    Stock temp {};
    Stock stocks[10] = {
        Stock("A", 10, 30.0),
        Stock(),
        Stock("B", 20, 50)
    };
    
    const Stock* top = &stocks[0];
    for (int i = 0; i < 10; i++) {
        top = &top->topval(stocks[i]);//topval返回一个别名，前面需要加&
    }
    top->show();
    
    const Stock &most = hot_tip.topval(jock);
    most.show();//只能调用常成员函数
    
    Bakery b1;
    
    
    //实例化方法
    Stock fo("World Cabbage");
    Stock food = Stock("World Cabbage");
    Stock* foo = new Stock("World Cabbage");
    while(1) Stock s2;
    
    return 0;
}
