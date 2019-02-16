#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    cout << "Enter an integer : ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for(int i = 0; i < 100; i += by)
    {
        cout << i << endl;
    }
    

    cout<<endl;
    return 0;
}
