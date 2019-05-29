#include <stdio.h>
#include "test2.h"

/**
 * 变长参数的宏定义以及__VA_ARGS__
 */ 
#define LOG(...) {\
    fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

int testp2_4(){
    int x = 3;
    LOG("x = %d", x);
    return 0;
}