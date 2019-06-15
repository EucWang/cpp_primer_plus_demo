#include <iostream>
#include "test8.h"
using namespace std;

void dosomething1(){
    cout << __func__ << "() called." << endl;
}

void dosomething2(){
    cout << __func__ << "() called." << endl;
}

/**
 * ⚠️：[[noreturn]]  和 void的区别
 */
[[noreturn]] void throwArray(){
    cout << __func__ << "() called." << endl;
    throw "exception";
}

/**
 * 错误使用[[noreturn]]的情况
 */
[[noreturn]] void func11(int i) {
    if(i < 0) {
        throw "negative";
    } else if (i > 0) {
        throw "positive";
    }
}


void testp8_11(){
    cout << __func__ << "() called. \n";
    // dosomething1();
    // throwArray();
    // dosomething2();

    func11(0);
    cout << "returned" << endl;

    cout << __func__ << "() called. done.\n";
}
