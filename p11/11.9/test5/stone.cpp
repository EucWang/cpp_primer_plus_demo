#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

// void display(const Stonewt & st, int n);

int main(){

    Stonewt poppins(9, 2.8);
    double p_wt = (double)poppins;  //将对象转换成 double类型
    
    cout << "Convert to  double => ";
    cout << "Poppins : " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n"; //明确指定需要将对象转换成int的基本数据类型， 就可以避免二义性

    cout<<poppins<<endl;

    poppins.set_type(POUND_TYPE);
    cout<<poppins<<endl;

    Stonewt st2(140);

    Stonewt st3 = poppins + st2;
    st3.set_type(POUND_TYPE);
    cout << st3  << endl;

    Stonewt st4 = poppins - st2;
    st4.set_type(POUND_TYPE);
    cout << st4  << endl;

    Stonewt st5 = poppins * st2;
    st5.set_type(STONE_TYPE);
    cout << st5 << endl;

    return 0;
}
 