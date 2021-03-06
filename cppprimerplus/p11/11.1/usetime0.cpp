#include <iostream>
#include "mytime0.h"
using namespace std;


int main132() {
    
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = " ;
    planning.show();
    cout << endl;

    cout << "coding time = " ;
    coding.show();
    cout << endl;

    cout << "fixing time = " ;
    fixing.show();
    cout << endl;

    total = coding.sum(fixing);
    cout << "total time = " ;
    total.show();
    cout << endl;

    return 0;
}
