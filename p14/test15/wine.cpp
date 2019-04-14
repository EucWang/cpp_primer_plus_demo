//
// Created by 王新年 on 2019-04-09.
//

#include "wine.h"
#include "../test14/pairs.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace Wine15 {
    Wine::Wine(const char *l, int y, const int yr[], const int bot[])
            : std::string(l), year(y), madeyears(ArrayInt(yr, y), ArrayInt(bot, y)) {}

    int Wine::getBottles() {
        int tmpYear;
        int tmpCount;

        cout << "Enter " << (std::string) (*this) << " data for " << year << " year(s)" << endl;
//    madeyears = PairArray(ArrayInt(year), ArrayInt(year));
        for (int i = 0; i < year; i++) {
            cout << "Enter year :";
            cin >> madeyears.first()[i];
            cout << "Enter bottles for that year: ";
            cin >> madeyears.second()[i];
        }
    }

    int Wine::sum() {
        return madeyears.second().sum();
    }

    void Wine::show() {
        cout << "Wine: " << (std::string) (*this) << endl;
        cout << "\tYear\tBottles" << endl;
        for (int i = 0; i < madeyears.first().size(); ++i) {
            cout << "\t" << madeyears.first()[i] << "\t" << madeyears.second()[i] << endl;
        }
    }
}

