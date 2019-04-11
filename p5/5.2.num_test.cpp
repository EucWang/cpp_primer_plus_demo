#include <iostream>


int main32()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    cout << "Enter the starting count down value: ";
    int limit;
    cin >> limit;
    int i;
    for(i = limit; i; i--)    //i==0 时条件为false，终止
    {
        cout << "i = " << i << endl;
    }
    cout << "Done now that i = " << i << endl;

    cout<<endl;
    return 0;
}
