#include <iostream>
#include "mytime3.h"
using namespace std;

int main101() {
    
    Time3 planning;
    Time3 weeding(4, 25);
    Time3 waxing(2, 47);
    Time3 total;
    Time3 diff;
    Time3 adjusted;

    cout << "weeding Time3 = " ;
    // weeding.show();
    cout << weeding;
    cout << endl;

    cout << "waxing Time3 = " ;
    // waxing.show();
    cout << waxing;
    cout << endl;

    cout << "total work Time3 = " ;
    total = weeding + waxing;
    // total.show();
    cout << total;
    cout << endl;


    diff = weeding - waxing;
    cout << "weeding - waxing Time3 = " << diff;
    // diff.show();
    cout << endl;

    adjusted =  1.5 * total;
    cout << "adjusted work Time3 = " << adjusted;
    // adjusted.show();

    cout << endl;

    return 0;
}
