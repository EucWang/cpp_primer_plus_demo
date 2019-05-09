#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "test16.h"

using namespace std;

/**
 * 为Review提供的成员或者非成员 的 operator< 操作符，
 * 那么调用 sort()函数时会默认调用这个  operator< 操作符函数来排序
 * 
 * 也可以为sort（）指定第三个参数用于排序
 * 
 * 
 * for_each() 第三个参数接受一个函数， 这个函数接受一个参数，
 */ 
bool operator<(const  shared_ptr<Review2>  r1, const  shared_ptr<Review2>  r2);
// bool operator<(const Review2 * r1, const Review2 * r2);
bool worseThan2(const  shared_ptr<Review2>  r1, const  shared_ptr<Review2>  r2);

bool epensiveThan(const shared_ptr<Review2>  r1, const  shared_ptr<Review2> r2);

int test10in16(){

    // vector<Review2> books;
    vector<shared_ptr<Review2>> books;
    // Review2 temp;
    // while(fillReview2(temp)) {
    //     books.push_back(temp);
    // }
    while(true) {
        shared_ptr<Review2> tmp(new Review2());
        if(!fillReview2(*tmp)){
            break;
        }
        books.push_back(tmp);
    }

    if(books.size() > 0) {
        cout << "Thank you. You entered the follwing " 
            << books.size() << " ratings: \n";
        cout << "Normal:\n";
        cout << "Rating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), showReview2);

        sort(books.begin(), books.end());
        cout << "\nSorted by title:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), showReview2);

        cout << "\nSorted by title desc:\nRating\tBook\tPrice\n";
        for_each(books.rbegin(), books.rend(), showReview2);

        sort(books.begin(), books.end(), worseThan2);
        cout << "\nSorted by rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), showReview2);

        cout << "\nSorted by rating desc:\nRating\tBook\tPrice\n";
        for_each(books.rbegin(), books.rend(), showReview2);

        sort(books.begin(), books.end(), epensiveThan);
        cout << "\nSorted by price:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), showReview2);

        cout << "\nSorted by price desc:\nRating\tBook\tPrice\n";
        for_each(books.rbegin(), books.rend(), showReview2);

        random_shuffle(books.begin(), books.end());
        cout << "\nAfter shuffling:\nRating\tBooks\tPrice\n";
        for_each(books.begin(), books.end(), showReview2);
    } else {
        cout << "No entries.\n";
    }

    cout << "Bye.\n";
    return 0;
}

bool operator<(const  shared_ptr<Review2>  r1, const shared_ptr<Review2> r2) {
    if(r1->title < r2->title ) {
        return true;
    } else if(r1->title == r2->title && r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

// bool operator<(const Review2 * r1, const Review2 * r2) {
//     if(r1->title < r2->title ) {
//         return true;
//     } else if(r1->title == r2->title && r1->rating < r2->rating) {
//         return true;
//     } else {
//         return false;
//     }
// }

bool worseThan2(const shared_ptr<Review2>  r1, const  shared_ptr<Review2> r2) {
    if(r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

bool epensiveThan(const shared_ptr<Review2>  r1, const  shared_ptr<Review2> r2) {
    if(r1->price < r2->price) {
        return true;
    } else {
        return false;
    }
}