//
//  stonewt.cpp
//  Operator
//
//  Created by Yukun on 2021/9/8.
//

#include "stonewt.hpp"
#include <iostream>

Stonewt::Stonewt(double lbs){
    stone = (int)lbs /Lbs_per_stn;
    pds_left = (int) lbs % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(long lbs){
    stone = (int)lbs /Lbs_per_stn;
    pds_left = (int) lbs % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt(){
    
}

void Stonewt::show_lbs() const{
    std::cout << stone << " stone, " << pds_left << " pounds.\n";
}

void Stonewt::show_stn() const{
    std::cout << pounds << "pounds.\n";
}

Stonewt::operator double() const{
    return pounds;
}

//Stonewt Stonewt::operator+(const Stonewt& t) const{Stonewt a();return a;}
Stonewt operator+(const Stonewt& t,const Stonewt& p){return Stonewt(20);}
