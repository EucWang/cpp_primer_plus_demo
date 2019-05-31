#include <iostream>
#include "test2.h"


/**
 * 显示的外部模板声明
 */ 
extern template void fun<int>(int);

int testp2_28(){
    fun(34);

    std::cout << "testp2_28()" << std::endl;
    return 0;
}