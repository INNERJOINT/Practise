//
//  main.cpp
//  DataType
//
//  Created by Yukun on 2021/8/24.
//

#include <iostream>
#include <codecvt>
#include <climits>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    /*
     各种类型变量所占用的字节数
     */
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    
    cout << "int is " << sizeof(int) << " bytes." <<endl;
    //cout << "short is " << sizeof(short) << " bytes." <<endl;
    cout << "short is " << sizeof n_short << " bytes." <<endl;
    //cout << "long is " << sizeof(long) << " bytes." <<endl;
    cout << "long is " << sizeof n_long << " bytes." <<endl;
    //cout << "long long is " << sizeof(long long) << " bytes." <<endl;
    cout << "long long is " << sizeof n_llong << " bytes." <<endl;
    cout << endl;
    
    cout << "Maxium values:" <<endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;
    cout << endl;
    
    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl << endl;
    
    /*
     三种初始化方式
     1. =
     2. 括号
     3. 大括号 C++11后引入，适用于任何类型赋值 (可不赋值，默认为0）
     */
    int owls = 101;
    int wren(402);
    int hamburgers = {24};
    int rocs{25};
    int rheas = {};
    int psychics{};
    auto owner = 2147483647L;
    
    cout << "owner :"<< owner <<" sizeof: "<< sizeof(owner) << endl;
    cout << owls << "\t" << wren << "\t" << hamburgers << "\t" << rocs << endl;
    cout << rheas << "\t" << psychics << endl << endl;
    
    /*
     转义字符的三种表达方式
     1. 符号序列 \n
     2. 数字序列 十六进制  \xA
     3.         八进制   \012
     */
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:______\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\xA";
    cout << "\aCode Verified!Proceed with Plan Z3!\012\012";
    
    /*
     通用字符名 Unicode
     一开始存在两个机构 ISO 和 统一码联盟
     USC是ISO提出来的编码
     对比          UTF-8      UTF-16      UTF-32      UCS-2       UCS-4
     编码空间    0-10FFFF    0-10FFFF    0-10FFFF    0-FFFF    0-7FFFFFFF
     最少编码字节数    1           2           4           2           4
     最多编码字节数    4           4           4           2           4
     是否依赖字节序    否          是           是          是          是
     
     字节序 BE更符合一般的视觉逻辑
     00000000 11110110 大端序 BE
     11110110 00000000 小端序 LE
     
     \u00F6(8个十六进制位） 只有在基本多文种平面中的字符才能用16比特来编码 UCS-2
     \U000000F6(16个十六进制位）UCS-4
     */
    int k\u00F6rper;
    cout << "Let them eat g\u00E2teau.\n\n";
    
    /*
     宽字符 wchar_t 为底层（underlying)类型 具体实现根据系统不同可能会存在差异
     具体实现根据系统不同 可能为unsigned short 也可能是int
     在字符或字符串前加 L （L'P',L"tall")
     cout cin为char流 ，需使用wcout wcin
     */
    wchar_t bob = L'P';
    wcout << bob << endl;
    wcout << " bob sizes : " << sizeof bob << endl;
    wcout << L"tall" << endl << endl;
    
    
    /*
     char16_t 和 char32_t
     前缀u 和char16_t匹配
     前缀U 和char32_t匹配
     在VS中 需要注意u和U不能识别 前缀为L
     */
    char16_t ch1 = u'\u0023';// #号
    char32_t ch2 = U'\U00000023';
    wcout << "ch1: " << (wchar_t)ch1 << " sizeof ch1: " << sizeof(ch1) << endl;
    wcout << "ch2: " << (wchar_t)ch2 << " sizeof ch2: " << sizeof(ch2) << endl << endl;
    
    /*
     浮点数
     表示方法
     1. 1.234
     2. 2.52e+8
        2.52e8
        2.52e-8
        -2.52e8
     float 和 long double 表示方法
     1. 1.234f
        1.234F
        1.23E4F
     2. 2L
     */
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;
    
    cout << "tub = " << tub;
    cout << ",a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;
    
    cout << "mint = " << mint << " and a million mints = " << million * mint << endl;;
   
    // 浮点数精度问题
    float a = 2.34E+22f;
    float b = a + 1.0f;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "b - a = " << b - a << endl;
    
    /*
     类型转换
     1. 初始化和赋值进行的转换
     2. 以{}方式初始化
        不允许缩窄 即是当编译器明确一个值能够赋值给小类型时，注意，变量由于不确定性，不可以
     3. 表达式中的转换 （注：两个short变量计算过程中可能存在转化为int计算后再转化为short的结果）
     4. 传递参数时的转换
     5. 强制类型转换
        5.1 C风格  (typename) value
        5.2 C++风格 typename (value)
        5.3 强制类型转换运算符 static_cast<> 更加安全
     */
    const int cc = 66;
    int x = 66;
    //char c1 {31325}; ERROR!
    char c2 = {66};
    char c3 {cc};
    //char c4 = {x};   ERROR!
    x = 31325;
    char c5 = x; // 允许，只取右部分字节
    int y = c5;
    
    cout << c5 << endl;
    cout << y << endl;
    
    int auks, bats, coots;
    auks = 19.99 + 11.99;
    
    bats = (int) 19.99 + (int) 11.99;
    coots = int (19.99) + int (19.99);
    cout << "auks = " << auks << ", bats = " << bats << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is " << int(ch) << endl;
    cout << "Yes ,the code is " << static_cast<int>(ch) << endl;
    
    
    return 0;
}
