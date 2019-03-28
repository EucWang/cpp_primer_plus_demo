#include <iostream>
#include "dma.h"

int main() {

    using std::cout;
    using std::endl;

    DmaABC *p[3];
    p[0] = new BaseDMA("Portabelly", 8);
    p[1] = new LacksDMA("red", "Blimpo", 4);
    p[2] = new HasDMA("Mercator", "Buffalo Keys", 5);

    cout << "Displaying BaseDMA object: \n";
    // cout << shirt << endl;
    p[0]->view();

    cout << "Displaying LacksDMA object: \n";
    // cout << balloon << endl;
    p[1]->view();

    cout << "Displaying HasDMA object: \n" ;
    // cout << map <<endl;
    p[2]->view();

    LacksDMA balloon2((LacksDMA &)(*p[1]));   //显示的复制构造函数
    cout << "Result of LacksDMA copy : \n";
    // cout << balloon2 << endl;
    balloon2.view();

    HasDMA map2;
    map2 = (HasDMA &)(*p[2]);  //调用赋值运算符
    cout << "Result of HasDMA assignment:\n";
    // cout << map2 << endl;
    map2.view();

    return 0;
}