#include <iostream>
using namespace std;

int tom = 3;

int dick = 30;
static int harry = 300;

void remote_access();

int main223()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick,"
        << &harry << " = &harry\n";
    
    remote_access();
    //cout<<endl;
    return 0;
}
