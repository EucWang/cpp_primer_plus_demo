#include <iostream>
#include <array>

/**
 * 通过for循环计算阶乘
 */ 
const int ArSize = 100;
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    // long long factorials[ArSize];
    array<long double, ArSize> factorials;

    factorials[1] = factorials[0] = 1;
    for(int i = 2; i < ArSize; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }

    for(int i = 0; i < ArSize; i++)
    {
        cout << i << "! = " << factorials[i] << endl;
    }

    cout<<endl;
    return 0;
}
