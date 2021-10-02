//
//  main.cpp
//  Union
//
//  Created by Yukun on 2021/8/16.
//

#include <iostream>

/*
 共用体
 长度为最大成员的长度
 */
union one4all{
    int int_val;
    long long_val;
    double double_val;
};

/*
 结构体
 位字段 指定结构成员的位数
 */
struct torgle_register {
    unsigned int SN : 4;
    unsigned int : 4;
    bool goodIn : 1;
    bool goodTorgle : 1;
};



int main(int argc, const char * argv[]) {
    using std::cout;
    using std::cin;
    using std::endl;
    
    //共用体
    one4all pail;
    pail.int_val = 4;
    cout << sizeof(pail) << endl;
    cout << pail.int_val << endl;;
    pail.double_val = 1.38;
    cout << sizeof(pail) << endl;
    cout << pail.double_val << endl;
    
    /*
     匿名共用体
     */
    struct widget {
        char brand[20];
        int type;
        union{
            long id_num;
            char id_char[20];
        };
    };
    widget prize;
    if (prize.type == 1) {
        cin >> prize.id_num;
    } else {
        cin >> prize.id_char;
    }
    
    if (prize.type == 1) {
        cout << prize.id_num;
    } else {
        cout << prize.id_char;
    }
    
    return 0;
}
