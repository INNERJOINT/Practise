//
//  Stock.cpp
//  Class
//
//  Created by Yukun on 2021/9/5.
//

#include "Stock.hpp"

//内联函数也可定义在类声明中
//inline void Stock::set_tot(){
//    m_total_val = m_shares * m_share_val;
//}

Stock::Stock(){
    std::cout << "no param construct" << std::endl;
    heap = new int(0);
}

/*
 析构函数
 主要用于释放new申请的空间
 如果没有delete，会导致内存泄漏
 */
Stock::~Stock(){
    std::cout << "destruct" << " : " << m_company <<std::endl;
    if (heap != nullptr) delete heap;
}

Stock::Stock(const std::string &co, long n , double pr ){
    heap = nullptr;
    std::cout << "param construct" << std::endl;
    m_company = co;
    if (n < 0) {
        std::cout << "Number of share can't be nagetive; "
        << m_company << "shares set to 0.\n";
        m_shares = 0;
    }
    else m_shares = n;
    m_share_val = pr;
    set_tot();
}

void Stock::acquire(const std::string &co, long n = 0, double pr = 0){
    m_company = co;
    if (n < 0) {
        std::cout << "Number of share can't be nagetive; "
        << m_company << "shares set to 0.\n";
        m_shares = 0;
    }
    else m_shares = n;
    m_share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price){
    if (num < 0) {
        std::cout << "Number of share can't be nagetive; "
        "Transaction is aborted.\n";
    }
    else {
        m_shares += num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    if (num < 0) {
        std::cout << "Number of share can't be nagetive; \
         Transaction is aborted.\n";
    }
    else if (num > m_shares){
        std::cout << "You can't sell more than you hava! \
         Transaction is aborted.\n";
    }
    else{
        m_shares -= num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    m_share_val = price;
    set_tot();
}

void Stock::show() const{
    using std::cout;
    using std::ios_base;
    std::ios_base::fmtflags orig = std::cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    std::cout << "Company: " << m_company
    << " Shares: " << m_shares
    << "\n Share Price: $" << m_share_val;
    cout.precision(2);
    cout << " Total Worth: $" << m_total_val << std::endl;
    
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}


const Stock & Stock::topval(const Stock &s) const{
    if (s.m_total_val > m_total_val) {
        return s;
    }else{
        return *this;
    }
}
