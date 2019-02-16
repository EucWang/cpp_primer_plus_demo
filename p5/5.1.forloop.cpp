#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int i;
    for(i = 0; i < 5; i++)
    {
        cout << "C++ knows loops.\n";
    }
    cout << "C++  knows when to stop.\n";
    
    cout<<endl;
    return 0;
}
