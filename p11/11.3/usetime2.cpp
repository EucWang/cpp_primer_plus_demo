#include <iostream>
#include "mytime2.h"
using namespace std;


int main129() {
    
    Time2 planning;
    Time2 weeding(4, 25);
    Time2 waxing(2, 47);
    Time2 total;
    Time2 diff;
    Time2 adjusted;

    cout << "weeding time = " ;
    weeding.show();
    cout << endl;

    cout << "waxing time = " ;
    waxing.show();
    cout << endl;

    cout << "total work time = " ;
    total = weeding + waxing;
    total.show();
    cout << endl;


    diff = weeding - waxing;
    cout << "weeding - waxing time = " ;
    diff.show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.show();
    cout << endl;

    return 0;
}
