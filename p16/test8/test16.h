#ifndef TEST_16_H_
#define TEST_16_H_

#include <vector>
#include <iostream>
#include <memory>

struct Review2{
    std::string title;
    int rating;
    double price;
};

bool fillReview2(/*out*/Review2 & rr);
// void showReview2(const Review2 & rr);
void showReview2(const  std::shared_ptr<Review2>  rr);

template<class T>
void showVector(const char * tips, std::vector<T> & v) {
    std::cout << tips << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<T , char>(std::cout, " "));
    std::cout << std::endl;
}
int main_test1in16();

int test3in16();
int test4in16();
int test5in16();
int test6in16();
int test7in16();
int test8in16();
int test9in16();
int test10in16();
#endif