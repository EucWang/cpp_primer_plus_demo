#include <iostream>
#include <cassert>
#include "test2.h"


char * arrayAlloc(int n) {
    assert(n>0);  //断言， n必须大于0，否则崩溃

    if(n > 0){
        return new char[n];
    }else {
        return nullptr;
    }
}

int testp2_6(){

    char * a = arrayAlloc(0);

    return 0;
}