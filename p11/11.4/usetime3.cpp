#include <iostream>
#include "mytime3.h"
using namespace std;

int main() {
    
    Time planning;
    Time weeding(4, 25);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = " ;
    // weeding.show();
    cout << weeding;
    cout << endl;

    cout << "waxing time = " ;
    // waxing.show();
    cout << waxing;
    cout << endl;

    cout << "total work time = " ;
    total = weeding + waxing;
    // total.show();
    cout << total;
    cout << endl;


    diff = weeding - waxing;
    cout << "weeding - waxing time = " << diff;
    // diff.show();
    cout << endl;

    adjusted =  1.5 * total;
    cout << "adjusted work time = " << adjusted;
    // adjusted.show();

    cout << endl;

    return 0;
}
