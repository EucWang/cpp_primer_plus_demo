#include <iostream>

const int Fave = 27;

int main174()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int n;
    cout << "Enter a number in the rage 1-100 to find ";
    cout << "my favorite number:";
    do
    {
        cin >> n;
        if (n < Fave) {
            cout << "Too low -- guess again: ";
        }else if (n > Fave) {
            cout << "Too high -- guess agian: ";
        }else {
            cout << Fave << " is right!\n";
        }
    } while (n != Fave);
    
    cout<<endl;
    return 0;
}
