//
// Created by 王新年 on 2019-05-25.
//

#include <iostream>

template <typename T>
long double sum_value(const T t){
    return (long double)t;
}

template <typename T, typename... Args>
long double sum_value(const T& t, const Args&... args){
    long double sum0 = sum_value(args...);  //注意这里的调用方式，还是需要加上...
    long double retVal = t + sum0;
    return retVal;
}

int main_p18test3(){
    long double  a =  sum_value(1, 100L, 'c', 12.1);
    std::cout << a << std::endl;

    return 0;
}