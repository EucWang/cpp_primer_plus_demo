#include <string>
#include <iostream>
#include "test4.h"

using namespace std;

class White{};

class Black{};

/**
 * typeid(val)  获得 变量的类型的对应的 type_info类型
 * typeid(val).name()    type_info类型 的name
 * typeid(val).hash_code()   type_info类型 的唯一hashcode值
 * 
 */
void testp4_16(){

    White a;
    Black b;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    White c;
    bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());
    bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());

    cout << "same type ? " << endl;
    cout << boolalpha;
    cout << "A and B ? " << a_b_sametype << endl;
    cout << "A and C ? " << a_c_sametype << endl;

}