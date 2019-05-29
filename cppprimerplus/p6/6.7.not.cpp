#include <iostream>

#include <climits>

bool is_int(double);

int main204()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while(!is_int(num)){
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int(num);
    cout << "You're entered the integer "<< val << "\nBye\n";

    cout<<endl;
    return 0;
}

bool is_int(double x) 
{
    if(x < INT_MAX && x >= INT_MIN)
    {
        return true;
    }else 
    {
        return false;
    }
}