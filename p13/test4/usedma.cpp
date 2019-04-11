#include <iostream>
#include "dma.h"

int main124() {

    using std::cout;
    using std::endl;

    BaseDMA shirt("Portabelly", 8);

    LacksDMA balloon("red", "Blimpo", 4);

    HasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "Displaying BaseDMA object: \n";
    cout << shirt << endl;

    cout << "Displaying LacksDMA object: \n";
    cout << balloon << endl;

    cout << "Displaying HasDMA object: \n" ;
    cout << map <<endl;

    LacksDMA balloon2(balloon);   //显示的复制构造函数
    cout << "Result of LacksDMA copy : \n";
    cout << balloon2 << endl;

    HasDMA map2;
    map2 = map;  //调用赋值运算符
    cout << "Result of HasDMA assignment:\n";
    cout << map2 << endl;

    return 0;
}