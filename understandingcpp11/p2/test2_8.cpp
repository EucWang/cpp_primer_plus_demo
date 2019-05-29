#include <iostream>
#include <cassert>

using namespace std;

/**
 * 产生断言的时间应该在模板实例化时，即编译时期就应该报错。
 */ 
template <typename T, typename U>
int bit_copy(T & a, U & b) {
    assert(sizeof(b) == sizeof(a));
    memcpy(&a, &b, sizeof(b));
}

int testp2_8(){

    int a = 0x2468;
    double b;
    bit_copy(a, b);

    return 0;
}