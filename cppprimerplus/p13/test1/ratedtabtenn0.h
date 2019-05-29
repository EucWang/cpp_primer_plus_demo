#ifndef RATED_TAB_TENN_0_H_
#define RATED_TAB_TENN_0_H_

#include "tabtenn0.h"

class RatedPlayer : public TableTennisPlayer{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r = 0, const string & fn="none",
            const string  & ln="none", bool ht=false);
        RatedPlayer(unsigned int r, const TableTennisPlayer & rp);

        unsigned int getRating() const {return rating;};
        void resetRating(unsigned int r) {rating = r; };
};

#endif