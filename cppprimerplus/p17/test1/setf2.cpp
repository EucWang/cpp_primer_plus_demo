#include <iostream>
#include <cmath>

/**
 * 17.9  
 * use setf() with 2 arguments to control formatting
 * 接收2个参数，并返回以前的设置
 * 第一个参数指出要设置哪位， 第二个参数指出要清除哪些位，
 * 
 * 具体来说，要修改基数， 可以将常量ios_base::basefield用作第二参数，将ios_base::hex作为第一参数
 * cout.setf(ios_base::hex, ios_base::basefield);  //设置16进制显示
 * 
 *  第二参数                    第一参数             含义
 *  ios_base::basefield        ios_base::dec             十进制
 *                             ios_base::oct             八进制
 *                             ios_base::hex             十六进制
 *  ios_base::floatfield       ios_base::fixed           定点计数法
 *                             ios_base::scientific      科学计数法
 *  ios_base::adjustfield      ios_base::left            左对齐
 *                             ios_base::right           右对齐
 *                             ios_base::internal        符号或基数前缀左对齐，值右对齐
 * 
 * 
 * c++中，定点表示法和科学计数法 有2个特征：
 * 1. 精度指的是小数位数， 而不是总位数
 * 2. 显示末尾的0
 * 
 * 
 * 标准控制符
 * 使用setf()使用不方便
 * 可以这样使用
 * cout << left << fixed;   //这样也可以打开左对齐 和定边表示法
 * 
 * 一些控制符
 * 
 * 控制符               调用
 * boolalpha           setf(ios_base::boolalpha)
 * noboolalpha         unset(ios_base::noboolalpha)
 * showbase            setf(ios_base::sowbase)
 * noshowbase          ...
 * showpoint
 * noshowpoint
 * showpos
 * noshowpos
 * uppercase
 * nouppercase
 * internal
 * left
 * right
 * dec 
 * hex
 * oct
 * fixed
 * scientific
 * 
 */ 
int main_setf2(){

    using namespace std;

    // use left justification, show the plus sign, show trailing zero, with a precision of 3
    cout.setf(ios_base::left, ios_base::adjustfield);  //左对齐
    cout.setf(ios_base::showpos);                      //显示正数+
    cout.setf(ios_base::showpoint);                    //显示全部精度的位数的数字, 末尾小数点后0补齐
    cout.precision(3);                                 //精度3位

    // use e-notation and save old format setting
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);  //科学计数法·
    cout << "Left Justification:\n";
    long n;
    for(n=1; n<=41; n+=10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // change to internal justification
    cout.setf(ios_base::internal, ios_base::adjustfield);  // 符号或基数前缀左对齐，值右对齐
    cout.setf(old, ios_base::floatfield);                  //显示以前的设置

    cout << "Internal Justifcation:\n";
    for(n =1; n<=41; n+=10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // use right justifcation, fixed notation
    cout.setf(ios_base::right, ios_base::adjustfield);     //右对齐
    cout.setf(ios_base::fixed, ios_base::floatfield);      //定点表示法
    cout << "Right Justification:\n";
    for(n=1; n<=41; n+=10) {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    return 0;
}