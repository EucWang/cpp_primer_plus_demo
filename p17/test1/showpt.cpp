#include <iostream>


/**
 * 17.7 
 * 
 * ios_base类提供了setf()函数，用于控制多种格式化特性
 * 
 * cout.setf(ios_base::showpoint); //显示全部精度的位数的数字
 * 
 * 格式化常量
 * ios_base::showpoint    显示全部精度的位数的数字, 末尾小数点后0补齐
 *  ios_base::boolalpha   输入输出bool值时可以为true，false
 * ios_base::showbase    对于输出，使用C++基数前缀（0， 0x）
 * ios_base::uppercase    对于16进制输出， 使用大写字母表示法
 * ios_base::showpos     再正数前面使用+
 */ 
int main_showpt(){

    using namespace std;
    using std::ios_base;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 /9.0;

    cout.setf(ios_base::showpoint);   //显示全部的精度

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    cout.precision(2);

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    return 0;
}