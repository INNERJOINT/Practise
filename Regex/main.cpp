//
//  main.cpp
//  Regex
//
//  Created by Yukun on 2021/9/4.
//

#include <iostream>
#include <regex>

/*
 正则表达式
 1. 特殊字符
    ^ 开始 或 不接受的字符集合
    $ 结尾
    | 两者中选择
    () 子表达式
    * 子表达式零次或多次 等价{0,}
    + 子表达式一次或多次 等价{1,}
    ? 字表达式零次或一次 等价{0,1}
    . 除\n以外
    
 */

int main(int argc, const char * argv[]) {
    using namespace std;
    
    string fnames[] {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname : fnames) {
        cout << fname << ": " << regex_match(fname, txt_regex) << endl;
    }
    
    
    return 0;
}
