#ifndef VECT_H_
#define VECT_H_

#include <string>

struct Review{
    std::string title;
    int rating;
};


bool fillReview(/*out*/Review & rr);
void showReview(const Review & rr);


int main_vect1();
int main_vect2();
int main_vect3();


#endif