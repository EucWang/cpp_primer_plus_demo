#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int num = 2;
    int result;
    // for(int i = 0; i < 7; i++)
    // {
    //     result = pow(num, i);
    //     cout << result << "\t";
    // }
    for(int i = 1; i <= 64; i *= 2)
    {
        cout << i << "\t";
    }

    //无效语句
    // int x = {1, 024};
    // cout << endl << x;
    
    cout<<endl;
    return 0;
}
