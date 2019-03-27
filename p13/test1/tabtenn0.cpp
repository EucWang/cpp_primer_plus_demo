#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht):
    firstname(fn), lastname(ln), hasTable(ht) {

    }

void TableTennisPlayer::name() const {
    std::cout << lastname << ", " << firstname;
}