#include <iostream>
#include "test4.h"

using namespace std;

/**
 * 使用decltype 类型推导 得到的类型作为指定 变量的类型
 * decltype总是以一个普通的表达式为参数 ，返回该表达式的类型 。
 * 而与 auto相同的是 ，作为一个类型指示符 ，decltype可以将获得的类型来定义另外一个变量 。
 */
void testp4_17(){

    cout << __func__ << "() called.\n";

    int i;
    decltype(i) j =0;
    cout << typeid(j).name() << endl;

    float a;
    double b;
    decltype(a + b) c;
    cout << typeid(c).name() << endl;
    
    cout << __func__ << "() called. done.\n";
}