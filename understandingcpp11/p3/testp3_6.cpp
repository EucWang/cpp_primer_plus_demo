#include <iostream>
#include "test3.h"

using namespace std;

/**
 * 完美转发的一个作用就是作为包装函数
 * C++11标准库中有大量完美转发的实际应用，比如
 * make_pair, make_unique等在C++11都是通过完美转发实现了。
 * 这样可以减少一些函数版本的重复（const和非const 版本的重复）
 * 并能够充分利用移动语义。
 * 
 */ 
template<class T, class U> 
void perfectForward(T && t, U & func) {
    cout << t << "\tforwarded .. " << endl;
    func(forward<T>(t));
}

void runCode(double && m){cout << __func__ <<  "(double &&) called.\n";}

void runHome(double && h){cout << __func__ << "(double &&) called.\n";}

void runComp(double && c){cout << __func__ << "(double && ) called.\n";}

void testp3_6(){
    cout << __func__ << "() called.\n";

    perfectForward(1.5, runComp);
    perfectForward(8, runCode);
    perfectForward(1.5, runHome);

    cout << __func__ << "() called done.\n";
}