#include <iostream>
using namespace std;


int main248()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int rats = 101;
    int& rodents = rats;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    rodents++;    
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;


    cout<<endl;
    return 0;
}
