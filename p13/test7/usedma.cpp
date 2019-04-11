#include <iostream>
#include "dma.h"

int main121() {

    using std::cout;
    using std::endl;

    DmaABC *p[3];
    p[0] = new BaseDMA7("Portabelly", 8);
    p[1] = new LacksDMA7("red", "Blimpo", 4);
    p[2] = new HasDMA7("Mercator", "Buffalo Keys", 5);

    cout << "Displaying BaseDMA7 object: \n";
    // cout << shirt << endl;
    p[0]->view();

    cout << "Displaying LacksDMA7 object: \n";
    // cout << balloon << endl;
    p[1]->view();

    cout << "Displaying HasDMA object: \n" ;
    // cout << map <<endl;
    p[2]->view();

    LacksDMA7 balloon2((LacksDMA7 &)(*p[1]));   //显示的复制构造函数
    cout << "Result of LacksDMA7 copy : \n";
    // cout << balloon2 << endl;
    balloon2.view();

    HasDMA7 map2;
    map2 = (HasDMA7 &)(*p[2]);  //调用赋值运算符
    cout << "Result of HasDMA assignment:\n";
    // cout << map2 << endl;
    map2.view();

    return 0;
}