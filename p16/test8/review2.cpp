
#include "test16.h"
#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;

bool fillReview2(/*out*/Review2 & rr) {
    cout << "Enter book title (q to quit): ";
    getline(cin, rr.title);
    if(rr.title == "q") {
        return false;
    }
    cout << "Enter book rating: " ;
    cin >> rr.rating;
    if(!cin) {
        return false;
    }
    while(cin.get() != '\n') {
        continue;
    }
    cout << "Enter book price: ";
    cin >> rr.price;
    if(!cin) {
        return false;
    }
    while(cin.get() != '\n') {
        continue;
    }
    return true;
} 

// void showReview2(const Review2 & rr){
//     cout << rr.rating << "\t" << rr.title << "\t" << rr.price << endl;
// }

void showReview2(const std::shared_ptr<Review2> rr){
    cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
}
