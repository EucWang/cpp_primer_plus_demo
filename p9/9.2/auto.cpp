#include <iostream>
using namespace std;

void oil(int x);


int main133() {
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    int texas = 31;
    int year = 2011;

    cout << "In main(), texas = " << texas << ", &texas = "
        << &texas << endl
        << "In main(), year = " << year << ", &year = "
        << &year << endl;

    oil(texas);

    cout << "In main(), texas = " << texas << ", &texas = "
        << &texas << endl
        << "In main(), year = " << year << ", &year = "
        << &year << endl;

    //cout<<endl;
    return 0;
}

void oil(int x) {
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", &texas = "
        << &texas << endl
        << "In oil(), x = " << x << ", &x = "
        << &x << endl;
    
    {
        int texas = 113;
        cout << "In block, texas = " << texas << ", &texas = "
        << &texas << endl
        << "In block, x = " << x << ", &x = "
        << &x << endl;
    }

    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}