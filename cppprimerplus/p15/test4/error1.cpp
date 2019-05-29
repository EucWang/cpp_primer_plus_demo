//error1.cpp using the abort() function

#include <iostream>
#include "error.h"

/**
 * abort()函数需要这个库
 */ 
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

double hmean(double a, double b);

int main_error1(){
    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y) {
        z = hmean(x, y);
        cout << "Harmonic mean of " << x << " and " << y 
            << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) {
    if(a==-b) {
        cout << "untenable arguments to hmean()\n";
        //调用 abort()函数将直接终止程序
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}