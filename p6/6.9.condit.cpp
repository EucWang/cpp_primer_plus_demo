#include <iostream>

/**
 * ?: 三元操作符
 * 
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int a,b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a> b ? a : b;
    cout << " is " << c << endl;

    cout<<endl;
    return 0;
}
