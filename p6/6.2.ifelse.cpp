#include <iostream>


int main169()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char ch;
    cout << "Type, and I shall repeat.\n";

    cin.get(ch);

    while( ch != '.')
    {
        if (ch == '\n') {
            cout << ch;
        }else {
            cout << ++ch;
            // cout << (ch + 1);
        }
        cin.get(ch);
    }
    cout << "\nPlease excuse the slight confusion.\n";

    cout<<endl;
    return 0;
}
