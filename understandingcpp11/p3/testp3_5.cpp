#include <iostream>
#include "test3.h"

using namespace std;

void runCode(int && m){cout << "rvalue ref" << endl;}

void runCode(int & m){cout << "lvalue ref" << endl;}

void runCode(const int && m) {cout << "rvalue ref" << endl;}

void runCode(const int & m) {cout << "const lvalue ref" << endl;}

/**
 * 完美转发 ： perfect forwarding
 * 是指在函数模板中， 完全依照模板的参数类型，将参数传递给函数模板中调用的另外一个函数.
 * 
 * "引用折叠"  reference collapsing 的语言规则
 * 用于处理目标函数的入参 可能时左值，可能const的左值，还有可能是右值，等不同情况
 * 
 * froward 用于实现完美转发的函数
 * forward 和 move 实际差别并不大。
 * std::move 实际就是一个static_cast 
 * 
 * 完美转发  的一个作用就是 做 包装函数。
 */ 
template<class T>
void perfectForward(T && t){ runCode(forward<T>(t));}

void testp3_5(){

    int a;
    int b;
    const int c = 1;
    const int d = 0;

    perfectForward(a);
    perfectForward(move(b));
    perfectForward(c);
    perfectForward(move(d));
    
}