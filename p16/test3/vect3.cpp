/**
 *  16.9 vect3.cpp 
 * using STL function
 * 
 * for_each()
 * random_shuffle()
 * sort() 
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "vect.h"

/**
 * 为Review提供的成员或者非成员 的 operator< 操作符，
 * 那么调用 sort()函数时会默认调用这个  operator< 操作符函数来排序
 * 
 * 也可以为sort（）指定第三个参数用于排序
 * 
 * 
 * for_each() 第三个参数接受一个函数， 这个函数接受一个参数，
 */ 
bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main_vect3(){

    vector<Review> books;
    Review temp;
    while(fillReview(temp)) {
        books.push_back(temp);
    }

    if(books.size() > 0) {
        cout << "Thank you. You entered the follwing " 
            << books.size() << " ratings: \n"
            << "Rating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

        sort(books.begin(), books.end());
        cout << "\nSorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "\nSorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

        random_shuffle(books.begin(), books.end());
        cout << "\nAfter shuffling:\nRating\tBooks\n";
        for_each(books.begin(), books.end(), showReview);
    } else {
        cout << "No entries.\n";
    }

    cout << "Bye.\n";
    return 0;
}


bool operator<(const Review & r1, const Review & r2) {
    if(r1.title < r2.title ) {
        return true;
    } else if(r1.title == r2.title && r1.rating < r2.rating) {
        return true;
    } else {
        return false;
    }
}

bool worseThan(const Review & r1, const Review & r2) {
    if(r1.rating < r2.rating) {
        return true;
    } else {
        return false;
    }
}