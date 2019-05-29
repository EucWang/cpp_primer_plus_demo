#include <iostream>
#include <string>
#include "test2.h"

const char* hello(){return __func__;}
const char * world(){return __func__;}

int testp2_2(){

    std::cout << hello() << ", " << world() << std::endl;
    return 0;
}