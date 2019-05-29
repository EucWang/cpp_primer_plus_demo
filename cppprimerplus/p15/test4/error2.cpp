#include <iostream>
#include <cfloat>  // for DBL_MAX

#include "error.h"


using std::cout;
using std::cin;
using std::endl;

/**
 * 设置返回值为bool，表示调用成功还是失败，
 * 增加第三个参数，用于提示调用失败的原因
 */ 
bool hmean2(double a, double b, double * ans);

int main_error2(){

    double x, y, z;
    cout << "Enter two numbers: ";
    while(cin >> x >> y) {
        if(hmean2(x, y, &z)){
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
        } else {
            cout << "One value should not be the negative "
                << "of the other - try again.\n";
            cout << "Enter next set of numbers <q to quit>: ";
        }
    }

    cout << "Bye.\n";
    return 0;
}

bool hmean2(double a, double b, double * ans) {
    if(a==-b) {
        *ans = DBL_MAX;
        return false;
    }else {
        *ans = 2.0 * a * b / (a+b) ;
        return true;
    }
}