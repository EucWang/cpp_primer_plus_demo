#ifndef WINE_H_
#define WINE_H_

#include <string>
#include <valarray>
#include "pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine{
    private:
        int year;
        std::string name;
        PairArray madeyears;
    public:
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y):name(l),year(y),madeyears(ArrayInt(y), ArrayInt(y)){};

        int getBottles();
        std::string & label(){return name;};
        int sum();
        void show();

};

#endif