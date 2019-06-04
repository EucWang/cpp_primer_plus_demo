#include <iostream>
#include <type_traits>

#include "test3.h"

using namespace std;

/**
 * 在C++11中，如果一个类型是平凡的并且是标准布局属性的，那么这个类型就是POD
 * 通过头文件 <type_traits> 中的模板类 的value属性可以判断
 * 
 * template <typename T>
 * struct std::is_pod;
 * 
 * std::is_pod<T>::value 
 */ 


/**
 * POD 的好处：
 * 1. 字节赋值， 可以安全的使用 memset 和memcpy对POD类型进行初始化和复制等操作
 * 2. 对C内存布局兼容
 * 3. 保证类静态初始化的安全有效。
 */ 

union U{};

union U1{U1(){}};  //有构造函数

enum E{};

typedef double * DA;

typedef void (*PF)(int, double);

void testp3_14(){
    cout << __func__ << "() called.\n";

    cout << boolalpha;
    cout << "union U is pod : \t" << is_pod<U>::value << endl;
    cout << "union U1 is pod : \t" << is_pod<U1>::value << endl;
    cout << "enum E is pod : \t" << is_pod<E>::value << endl;

    cout << "double * is pod : \t" << is_pod<DA>::value << endl;
    cout << "void (*)(int, double) is pod : \t" << is_pod<PF>::value << endl;

    cout << __func__ << "() called. done. \n";
}