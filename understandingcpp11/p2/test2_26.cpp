#include <iostream>
#include "test2.h"

using namespace std;

template<typename T>
void tempFun(T a) {
    cout << a << endl;
}

int testp2_26(){
    tempFun(1);
    tempFun("123");

    return 0;
}