/*
    show hex and octal literals
    十进制，十六进制(hex)  八进制(octal)，  表示数字
*/
#include <iostream>

using namespace std;

int main162()
{

    int chest = 42;       //十进制
    int waist = 0x42;      //十六进制
    int inseam = 042;    //八进制 

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest " << chest << " (42 in decimal)" <<endl;
    cout << "waist " << waist << " (0x42 in hex)" << endl;   
    cout << "inseam " << inseam << " (042 in octal)" << endl;

    return 0;
}