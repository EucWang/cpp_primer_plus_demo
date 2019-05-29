#include <iostream>
#include "error.h"

using std::cout;
using std::cin;
using std::endl;

double hmean3(double a, double b);

int main_error3(){
    double x, y, z;

    cout << "Enter a pair of numbers: ";
    while(std::cin >> x >> y) {
        try{  //在这里尝试执行，并尝试捕获异常
            z = hmean3(x, y);
        }catch(const char * s) {  //捕获异常，并处理
            cout << s << endl;
            cout << "Enter a new pair of numbers: ";
            continue;
        }

        cout << "Harmonic mean of " << x << " and " << y    
            << " is " << z << endl;

        cout << "Enter next set of numbers <q to quit> : ";
    }

    cout << "Bye.\n";

    return 0;
}

double hmean3(double a, double b) {
    if(a==-b) {
        //抛出异常对象，这里直接抛出一个string
        throw "bad hmean() arguments: a==-b not allowed.";
    }
    return 2.0 * a * b / (a + b);
}