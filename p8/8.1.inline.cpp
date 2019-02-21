#include <iostream>
using namespace std;

inline double square(double x) {return x*x;}

int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double a,b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << endl;
    cout << "Now c = " << c << endl;
    
    cout<<endl;
    return 0;
}
