#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int a= 20;
    int b = 20;

    cout << "a = " << a << ",  b = " << b << endl;
    cout << "a++ = " << a++ << ", ++b = " << ++b << endl;
    cout << "a = " << a << ", b = " << b << endl;

    cout<<endl;
    return 0;
}
