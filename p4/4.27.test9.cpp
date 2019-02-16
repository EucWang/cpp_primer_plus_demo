#include <iostream>
#include <array>
#include <string>

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    string tip = "Please enter score : ";

    array<double, 3> arr;

    for(int i=0; i<3; i++) {
        cout << tip;
        cin >> arr[i];
        cin.get();
    }
    
    cout << "scores : ";
    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    

    cout<<endl;
    return 0;
}
