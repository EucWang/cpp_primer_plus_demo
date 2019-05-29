
#include <cstring>
#include <iostream>

using namespace std;


/**
 * 忽略掉 do..while 部分
 * 将 参数e 代入 到  表达式 1/e， 即 e表达式不能为0，即不能为false，
 * 从而可以实现断言功能，在编译就可以抛出错误提示,但是提示信息就变成了 除0错误
 * 
 * Boost库内置的BOOST_STATIC_ASSERT 如果编译错误会是sizeof错误
 * 
 * C++11标准中，引入了static_assert断言来解决 错误提示不准确的问题
 * static_assert断言的结果必须是在编译时期就可以计算的表达式， 如果使用变量，则会导致错误
 */ 
#define assert_static(e) \
    do { \
        enum { assert_static__  = 1/(e)}; \
    } while(0)

// template <typename T, typename U> 
// int bit_copy(T & a, U & b) {
//     assert_static(sizeof(b) == sizeof(a));
//     memcpy(&a, &b, sizeof(b));
// }

template <typename T, typename U> 
int bit_copy(T & a, U & b) {
    static_assert(sizeof(a) == sizeof(b), "the parameters of bit_copy must have same width.");
    memcpy(&a, &b, sizeof(b));
    return 1;
}

/**
 * 当前文件不能通过编译，如果 是 double b， 而不是 int b
 */ 
int testp2_9(){

    int a = 0x2468;
    // double b;
    char b[4];
    bit_copy(a, b);
    return 0;
}