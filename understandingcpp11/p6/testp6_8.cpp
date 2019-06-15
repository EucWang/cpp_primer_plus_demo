#include <iostream>
#include "test6.h"
using namespace std;

/**
 * Fibonacci 的val是静态的，并且定义方式是递归的。
 * 因此模板会递归的进行推导。
 * 再编译阶段就可以进行值计算，从而生成数组的值。
 * 
 */
template <long num>
struct Fibonacci {
    static const long val = Fibonacci<num - 1>::val + Fibonacci<num - 2>::val;
};

template <> 
struct Fibonacci<2> {
    static const long val = 1;
};

template <>
struct Fibonacci<1> {
    static const long val = 1;
};

template <>
struct Fibonacci<0> {
    static const long val = 0;
};

void testp6_8(){
    int fib[] = {
        Fibonacci<11>::val, Fibonacci<12>::val,
        Fibonacci<13>::val, Fibonacci<14>::val,
        Fibonacci<15>::val, Fibonacci<16>::val,
    };
    for(int i : fib) {
        cout << i << endl;
    }
}
