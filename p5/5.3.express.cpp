#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int x;
    cout << "The expression x = 100 has the value " ;
    cout << (x = 100) << endl;

    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    // 通常 cout 在显示bool值之前将它们转换成int，就是输出0，1
    // 通过设置 ios_base::boolalpha之后，cout将bool值输出为true和false，而不是0，1
    cout.setf(ios_base::boolalpha); //a newer C++ feature  

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout<<endl;
    return 0;
}
