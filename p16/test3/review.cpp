
#include "vect.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool fillReview(/*out*/Review & rr) {
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
    return true;
} 

void showReview(const Review & rr){
    cout << rr.rating << "\t" << rr.title << endl;
}
