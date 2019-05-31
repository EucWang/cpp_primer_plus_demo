#include <iostream>
#include "test2.h"

/**
 * 显示的外部模板实例化声明， 
 */ 
extern template void fun<int>(int);

int testp2_28_3(){
    fun(100);
    std::cout << " testp2_28_3\n";
}