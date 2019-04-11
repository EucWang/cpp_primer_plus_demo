#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

// void display(const Stonewt96 & st, int n);

int main74(){
    Stonewt96 a[6] = {
        Stonewt96(7),
        Stonewt96(14),
        Stonewt96(21)
    };

    for(int i=3; i<(sizeof(a)/sizeof(Stonewt96)); i++) {
        a[i].set_pounds(i*4+140);
    }

    Stonewt96 * min = a;
    Stonewt96 * max = a;
    int countBigger = 0;
    Stonewt96 * one = &a[0];
    Stonewt96 b11 = Stonewt96(11, 0);
    for(int i=1; i<(sizeof(a)/sizeof(Stonewt96)); i++) {
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
    cout << "the min Stonewt96 is " << (*min) << endl;
    cout << "the max Stonewt96 is " << (*max) << endl;
    cout << "the count of ele not less than 11 stones is " << countBigger << endl;

    return 0;
}
 