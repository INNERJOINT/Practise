//
//  Emun.cpp
//  Practise
//
//  Created by Yukun on 2021/8/7.
//

#include "Emun.hpp"
#include <iostream>
#include <iomanip>
// emun <类型名> {<枚举常量表>};
enum color_set
{
    RED,
    BLUE,
    WHITE,
    BLACK
};

enum week
{
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

enum fruit_set
{
    apple,
    orange,
    banana = 1,
    peach,
    grape
};

// ERROR EXAMPLE
//enum letter_set
//{
//    'a',
//    'd',
//    'F',
//    's',
//    'T'
//};
//
//enum year_set
//{
//    2000,
//    2001,
//    2002,
//    2003
//};

enum letter_set
{
    a,
    d,
    F,
    s,
    T
};
letter_set l1, l2;

enum year_set
{
    y2000,
    y2001,
    y2002,
    y2003
}y2;

color_set color1, color2, color3, color4;

/* 口袋中有红、黄、蓝、白、黑五种颜色的球若干个，每次从口袋中取三个不同颜色的球，统计并输出所有的取法。*/
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    int i, j, k, counter = 0, loop;
    for (i = RED; i <= BLACK; i++) {
        for (j = RED; j <= BLACK; j++) {
            if (i != j) {
                for (k = RED; k <= BLACK; k++) {
                    if (k != i && k != j) {
                        counter++;
                        /* 每页显示22行 */
                        if (counter % 22 == 0) {
                            cout << "请按回车键继续";
                            cin.get();
                        }
                        std::cout << std::setw(15) << counter;
                        /* 下面输出各种取法，一行为一种取法的三种颜色 */
                        for (loop = 1; loop <= 3; loop++) {
                            switch (loop) {
                                case 1:
                                    color1 = color_set(i);
                                    break;
                                case 2:
                                    color1 = color_set(j);
                                    break;
                                case 3:
                                    color1 = color_set(k);
                                    break;
                                default:
                                    break;
                            }
                            switch (color1) {
                                case RED:
                                    cout << std::setw(15) << "RED";
                                    break;
                                case BLUE:
                                    cout << std::setw(15) << "BLUE";
                                    break;
                                case WHITE:
                                    cout << std::setw(15) << "WHITE";
                                    break;
                                case BLACK:
                                    cout << std::setw(15) << "BLACK";
                                    break;
                                default:
                                    break;
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
    cout << "共有：" << counter << "种取法" << endl;
    return 0;
}
