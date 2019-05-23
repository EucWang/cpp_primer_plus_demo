//
// Created by 王新年 on 2019-05-21.
//

#include "test1.h"
#include <iostream>

inline double f(double tf){return 5.0 * (tf - 32.0)/09.0;};

/**18.1
 * rvref.cpp
 * simple uses of rvalue references
 *
 * C++11 新增"右值引用"， 使用 && 表示
 * "右值引用" 可关联到右值（即出现咋赋值表达式右边，但不能对其应用地址运算符的值）
 * 将"右值引用"关联到"右值"将导致"右值"被存储到特定位置，并且可以获取该位置的地址。
 * 通过将数据与特定地址关联，使得可以通过"右值引用"来访问数据
 *
 * @return  int
 */
int main_rvref(){

    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07;
    double && rd2 = 1.8 * tc + 32;
    double && rd3 = f(rd2);

    cout << "tc value and address : " << tc << ", " << &tc << endl;
    cout << "rd1 value and address : " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 value and address : " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 value and address : " << rd3 << ", " << &rd3 << endl;
    cin.get();
    return 0;
}