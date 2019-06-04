#include <iostream>
#include "test3.h"
using namespace std;

/**
 * C++11中， 
 * 若联合体中 有 非POD成员，
 * 而且 该非POD成员 有自定义的构造函数，
 * 那么 联合体的默认构造函数 就会被编译器删掉，
 * 联合体的默认复制构造函数， 复制赋值操作符函数 ，以及析构函数 也遵从同样的规则。
 * 
 * 解决这个问题：
 * 需要为 联合体 自定义相应的构造函数 和 析构函数
 */ 

union T3 {
    string s;  //string是非POD成员， 且有自定义的构造函数
    int n;
public:
    T3() {
        new (&s) string;  //采用 placement new 将s构造在其地址&s上， 这里目的只是调用一下string的构造函数
    }
    ~T3() {
        //⚠️析构的时候union 必须是一个string对象，否则会导致析构出错。
        s.~string();  //调用string的析构函数
    }
};

void testp3_16(){
    cout << __func__ <<"() called.\n";

    //编译不会通过，抛出问题
    //default constructor of 'T3' is implicitly deleted because variant field 's' has a non-trivial default constructor
    // T3 t;

    T3 t3();

    cout << __func__ <<"() called. done\n";
}