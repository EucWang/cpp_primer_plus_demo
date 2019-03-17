#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

// void display(const Stonewt & st, int n);

int main(){
    Stonewt a[6] = {
        Stonewt(7),
        Stonewt(14),
        Stonewt(21)
    };

    for(int i=3; i<(sizeof(a)/sizeof(Stonewt)); i++) {
        a[i].set_pounds(i*4+140);
    }

    Stonewt * min = a;
    Stonewt * max = a;
    int countBigger = 0;
    Stonewt * one = &a[0];
    Stonewt b11 = Stonewt(11, 0);
    for(int i=1; i<(sizeof(a)/sizeof(Stonewt)); i++) {
        if(a[i] > *one) {
            max = &a[i];
        }
        if(a[i] < *one) {
            min = &a[i];
        }
        if(a[i] > b11 || a[i] == b11){
            countBigger++;
        }
    }
    cout << "the min Stonewt is " << (*min) << endl;
    cout << "the max Stonewt is " << (*max) << endl;
    cout << "the count of ele not less than 11 stones is " << countBigger << endl;

    return 0;
}
 