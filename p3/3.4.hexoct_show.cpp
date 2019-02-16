#include <iostream>

using namespace std;

int main()
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Moniseur cuts a striking figure." << endl;
    cout << "chest " << chest << " (decimal for 42)" << endl;

    cout << hex;   //不输出任何内容到屏幕上，只是修改整数显示的方式为16进制
    cout << "waist " << waist << " (hex for 42 十六进制)" << endl;

    cout << oct; //不输出任何内容到屏幕上，只是修改整数显示的方式为8进制
    cout << "inseam " << inseam << " (octal for 42 八进制)" << endl;

    cout << dec; //不输出任何内容到屏幕上，只是修改整数显示的方式为10进制
    cout << "chest " << chest << " (decimal for 42 正常十进制)" << endl;

    return 0;
}
