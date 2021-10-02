//
//  Tabletennis.hpp
//  Classimpl
//
//  Created by Yukun on 2021/9/18.
//

#ifndef Tabletennis_hpp
#define Tabletennis_hpp

#include <stdio.h>
#include <string>
using std::string;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    //静态成员
    //所有实例公用，且需要初始化
    static int count;
    TableTennisPlayer(const string & fn = "none",
                      const string & ln = "none",
                      bool ht = false);
    void Name() const;
    bool HasTable() const {return hasTable;};
    void ResetTable(bool v) {hasTable = v;};
};

#endif /* Tabletennis_hpp */
