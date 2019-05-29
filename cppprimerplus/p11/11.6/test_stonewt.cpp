#include <iostream>
#include "stonewt.h"

using namespace std;

int main200(){
    //如果构造函数只接受一个参数，
    //那么可以使用隐式的类型转换，直接将值作为左值赋值给对对象
    // Stonewt a = 12.5;
    // a.show_lbs();
    // a.show_stn();
    // return 0;

    // 为构造函数使用explicit 关键字，将关闭自动的隐式类型转换
    Stonewt a = Stonewt(12.5);
    a.show_lbs();
    a.show_stn();
    return 0;

}