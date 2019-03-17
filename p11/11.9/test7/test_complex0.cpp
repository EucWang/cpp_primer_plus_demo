#include <iostream>
using namespace std;

#include "complex0.h"

int main()
{
    complex a(3.0, 4.0);
    complex c;
    complex temp;
    cout << "enter a complex number (q to quit):\n";
    while(cin>>c) {
        cout << "c is "<< c << "\n";
        temp = ~c;
        cout << "complex conjugate is " << temp << "\n";
        cout << "a is "<< a << "\n";
        temp = (a+ c);
        cout << "a + c is " << temp << "\n";
        temp = a - c;
        cout << "a - c is " << temp << "\n";
        temp = a * c;
        cout << "a * c is " << temp << "\n";
        temp = 2*c;
        cout << "2 * c is " << temp << "\n";
        cout << "Enter a complex number(q to quit):\n";
    }

    return 0;
}
