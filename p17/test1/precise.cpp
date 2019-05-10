#include <iostream>

/**
 * 17.6 setting the precision
 * 
 * C++默认显示精度为6位数字， 也就是只显示一个数中的6个位数
 * precision就是控制这个位数的显示
 * 
 * 新的精度设置之后将一直有效
 * 
 */ 
int main_precise(){

    using namespace std;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    return 0;
}