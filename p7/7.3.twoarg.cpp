#include <iostream>

using namespace std;

void n_chars(char, int);

int main38()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    while(ch != 'q') {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times);
        cout << "\nEnter another character or press the q-key to quit: ";
        cin >> ch;
    }
    cout << "The value of times is " << times << ".\n";
    cout << "Bye";
    
    cout<<endl;
    return 0;
}

void n_chars(char c, int n) {
    while(n-- > 0) {
        cout << c;
    }
}