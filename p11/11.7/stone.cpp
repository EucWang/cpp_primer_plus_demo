#include <iostream>
#include "stonewt.h"

using std::cout;

void display(const Stonewt & st, int n);

int main(){

    Stonewt poppins(9, 2.8);
    double p_wt = (double)poppins;  //将对象转换成 double类型
    
    cout << "Convert to  double => ";
    cout << "Poppins : " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n"; //明确指定需要将对象转换成int的基本数据类型， 就可以避免二义性
    return 0;
}
 