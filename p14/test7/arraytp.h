#ifndef ARRAY_TP_H_
#define ARRAY_TP_H_

#include <iostream>
#include <cstdlib>

/**
 * 表达式参数
 * T为类型参数
 * int指出n的类型是int，这种参数成为非类型或表达式参数
 * 
 * ⚠️表达式参数有一些限制：
 * 可以是整型，枚举，引用或者指针
 * 并且模板代码不能修改参数的值，也不能使用参数的地址。
 */ 
template <class T, int n>
class ArrayTP {
    private:
        T ar[n];
    public:
        ArrayTP(){};
        explicit ArrayTP(const T & v);
        virtual T & operator[](int i);
        virtual T operator[](int i) const;
};

/**
 * 用同样的值填充数组
 */ 
template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v) {
    for(int i=0; i<n; i++) {
        ar[i] = v;
    }
};


template <class T, int n>
T & ArrayTP<T, n>::operator[](int i) {
    if( i<0 || i>n) {
        std::cerr << "Error in array limits: " << i
            << " is out of range\n";
        // std::exit[EXIT_FAILURE];
        return ar[0];
    }
    return ar[i];
};

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const {
    if( i<0 || i>n) {
        std::cerr << "Error in array limits: " << i
            << " is out of range\n";
        // std::exit[EXIT_FAILURE];
        return ar[0];
    }
    return ar[i];
};


#endif