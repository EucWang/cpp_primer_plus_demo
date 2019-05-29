//
// Created by 王新年 on 2019-05-22.
//  18.3 stdmove.cpp
// using std::move()

#include <utility>
#include <iostream>
#include "useless.h"
#include "test2.h"

/**
 * 如果同时 定义了  复制运算符  和 移动运算符  （都是 operator=()）
 *
 * 在调用 "=" 号时， 如何明确的 指出 这是调用 移动运算符而不是复制运算符，
 * 默认情况下， "=" 右边的值一般都是 "左值"，
 * 这时候需要将"左值"转换成"右值"，
 *
 * 1,可以使用 static_cast<> 运算符将对对象的类型强制转换为  Useless &&
 * 2，C++ 提供了 头文件 utility 中声明的函数 std::move() 实现这个功能
 *
 * ⚠️ ： 表达式std::move(one) 是右值，
 *       two = std::move(one) 这一句将调用定义好的移动赋值运算符（如果定义了这样的运算符，这是前提）
 *       如果Useless没有定义移动赋值运算符，编译器将使用复制赋值运算符（如果定义了复制赋值运算符，这也是前提）
 *       如果连复制赋值运算符都没有定义， 则编译器根本就不允许使用 "="进行赋值了。
 *
 *
 * @return
 */

int main_stdmove(){

    cout << "**************test main_stdmove()**************\n";
    using std::cout;

    Useless one(10, 'x');
    Useless two =  one + one;

    cout << "****************************\n";
    cout << "object one : ";
    one.showData();

    cout << "****************************\n";
    cout << "object two: ";
    two.showData();

    Useless three, four;
    cout << "****************************\n";
    cout << " three = one\n";
    three = one;
    cout << "****************************\n";
    cout << "now object three = ";
    three.showData();
    cout << "****************************\n";
    cout << "and object one = ";
    one.showData();

    cout << "****************************\n";
    cout << "four = one + two\n";
    four = one + two;
    cout << "now obejct four = ";
    four.showData();


    cout << "\n****************************\n";
    cout << "four  = move(one)\n";
    four = std::move(one);
    cout << "now object four = ";
    four.showData();
    cout << "and object one = ";
    one.showData();


    return 0;
}

