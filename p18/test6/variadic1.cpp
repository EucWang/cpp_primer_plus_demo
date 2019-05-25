#include <iostream>
#include <string>
#include "test6.h"

/**
 *  递归接受条件，没有参数的情况
 */ 
void show_list3(){
    // std::cout << "\nDone.\n";
}

/**
 * 添加处理一项的模板函数， 处理的这一项就是 可变参数的最后一项， 
 * 这样可以避免在最后一项后面多出来的“，”
 * 这也替代来
 */ 
template<typename T>
void show_list3(T value){
    std::cout << value << "\n";
}

/**
 * 使用递归来解包，
 * 模板递归参数， 可变参数， 参数类型不同
 * 
 * 用引用优化
 */ 
template<typename T, typename... Args>
void show_list3(const T& value, const Args&... args){
    std::cout << value << ", ";
    show_list3(args...);
}


/**
 * 18.9 variadic1.cpp
 * using recursion to unpack a parameter pack
 */ 
void main_variadic1() {
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects:";
    show_list3(n, x);
    std::cout << std::endl;

    show_list3(x * x, 7, mr);
    std::cout << std::endl;
}

