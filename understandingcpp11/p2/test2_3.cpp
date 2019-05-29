
#include <iostream>
#include "test2.h"

using namespace std;

struct TestStruct{
    TestStruct() : name(__func__){}  //结构体的默认构造函数，并初始化属性
    const char * name;
};

int testp2_3(){

    TestStruct ts;
    cout << ts.name << endl;

    return 0;
}