#include <iostream>


/**
 * 17.3 using format manipulators
 * 
 * ostream 从 ios类派生而来,
 * ios从ios_base派生而来
 * 
 * 要控制整数以十进制，十六进制还是八进制显示，
 * 可以使用dec, hex oct控制符。
 * 例如 ：将cout对象的计数系统格式化设置为十六进制
 * hex(cout)  或者  cout << hex;
 */ 
int main_manip(){
    using namespace std;

    cout << "Enter an integer:";
    int n;
    cin >>n ;

    cout << "n\tn*n\n";
    cout << n << "\t" << n*n << " (decimal)\n";

    cout << hex;
    cout << n << "\t" << n*n << " (hexadecimal)\n";  //16进制

    cout << oct;
    cout << n << "\t" << n * n << " (octal)\n"; //八进制

    dec(cout);
    cout << n << "\t" << n*n << " (decimal)\n";   //十进制

    return 0;
}