#include <iostream>
#include "mytime3.h"
using namespace std;

int main79() {
    
    Time94 planning;
    Time94 weeding(4, 25);
    Time94 waxing(2, 47);
    Time94 total;
    Time94 diff;
    Time94 adjusted;

    cout << "weeding Time94 = " ;
    // weeding.show();
    cout << weeding;
    cout << endl;

    cout << "waxing Time94 = " ;
    // waxing.show();
    cout << waxing;
    cout << endl;

    cout << "total work Time94 = " ;
    total = weeding + waxing;
    // total.show();
    cout << total;
    cout << endl;


    diff = weeding - waxing;
    cout << "weeding - waxing Time94 = " << diff;
    // diff.show();
    cout << endl;

    adjusted =  1.5 * total;
    cout << "adjusted work Time94 = " << adjusted;
    // adjusted.show();

    cout << endl;

    return 0;
}
