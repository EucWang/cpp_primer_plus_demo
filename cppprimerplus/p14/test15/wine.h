#ifndef WINE_H_
#define WINE_H_

#include <string>
#include <valarray>
#include "../test14/pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

namespace Wine15 {

    class Wine : std::string {
    private:
        int year;
//        std::string name;
        PairArray madeyears;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]);

        Wine(const char *l, int y) : std::string(l), year(y), madeyears(ArrayInt(y), ArrayInt(y)) {};

        int getBottles();

        std::string &label() { return *this; };

        int sum();

        void show();

    };
};
#endif