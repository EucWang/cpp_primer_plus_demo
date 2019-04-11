#include "port.h"
#include <iostream>

using namespace std;

int main120() {

    Port p1("Qindao", "Beer", 100);
    VintagePort p2("XueHua",  200, "SnowBeer", 2019);

    Port * tp;

    cout << "Testing using pointer to call show() and ostream \n";
    tp = &p1;
    tp->show();
    cout << "-=-=-=-=\n";
    cout << *tp << endl;

    cout << "====================\n";

    tp = &p2;
    tp->show();
    cout << "-=-=-=-=\n";
    cout << *tp << endl;  //友元函数不能动态联编

    cout << p2 <<endl;

    return 0;
}