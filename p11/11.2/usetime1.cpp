#include <iostream>
#include "mytime1.h"
using namespace std;


int main130() {
    
    Time1 planning;
    Time1 coding(2, 40);
    Time1 fixing(5, 55);
    Time1 total;

    cout << "planning Time1 = " ;
    planning.show();
    cout << endl;

    cout << "coding Time1 = " ;
    coding.show();
    cout << endl;

    cout << "fixing Time1 = " ;
    fixing.show();
    cout << endl;

    total = coding + fixing;
    cout << "total Time1 = " ;
    total.show();
    cout << endl;

    Time1 morefixing(3, 28);
    cout << "more fixing Time1 = ";
    morefixing.show();
    cout << endl;

    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.show();
    cout << endl;

    return 0;
}
