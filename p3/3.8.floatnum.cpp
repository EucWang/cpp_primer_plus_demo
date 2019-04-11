/**
 *  使用float和double类型
 *   
 */
#include <iostream>

int main160()
{
    using namespace std;
     //通常cout输出的float和double会自动不显示结尾的0，
     //通过调用方法 cout.setf() 可以让float和double完整的显示出来，
     //这样设置也可以避免使用浮点计数法来显示浮点数，而是直接显示完整的数值
    cout.setf(ios_base::fixed, ios_base::floatfield); 

    float stub = 10.0/3.0;
    double mint = 10.0/3.0;

    const float million = 1.0e6;

    cout << "stub = " << stub
        << ", a million stub = " << million * stub 
        << "\nand a ten million stub = " << 10 * million * stub << endl;
    cout << "mint = " << mint
        << ", a million mint = " << million * mint << endl;

    return 0;
}