#include <iostream>
#include "test2.h"


/**
 * 显示的模板实例化声明
 * 注意，这里不是外部模板实例化声明，而只是模板实例化
 */ 
template void fun<int>(int);

void testp2_28_1(){
    fun(1);
}