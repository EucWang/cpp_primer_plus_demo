#include <iostream>
#include <cassert>

using namespace std;

enum FeatureSupports {
    C99 = 0x0001,
    ExtInt = 0x0002,
    SAssert = 0x0004,
    NoExcept = 0x0008,
    SMAX = 0x0010, //通过最大枚举值，来判断其他所有枚举值的或运算是否存在枚举值重位的情况。
};

struct Compiler {
    const char * name;
    int spp;  //使用FeatureSupports枚举, 按位存储
};

int testp2_7(){

    //来判断其他所有枚举值的或运算是否存在枚举值重位的情况。
    //但是assert是运行时断言，如果不运行程序我们将无法得知是否有枚举重位的情况
    assert( (SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));

    Compiler a = {"abc", (C99 | SAssert)};
    if(a.spp & C99) {
        cout << "a.spp & C99 is true" << endl;
    }

    return 0;
}