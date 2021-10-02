//
//  Tabletennis.cpp
//  Classimpl
//
//  Created by Yukun on 2021/9/18.
//

#include "Tabletennis.hpp"
#include <iostream>

int TableTennisPlayer::count = 1;

TableTennisPlayer::TableTennisPlayer(const string & fn,
                                     const string & ln,
                                     bool ht) : firstname(fn), lastname(ln), hasTable(ht){}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
