#include <iostream>

void cheers0(int);

double cube0(double x);


int main58()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    cheers0(5);
    cout << "Give me a number : ";
    double side;
    cin >> side;
    double volume = cube0(side);
    cout << "A " << side << " foot cube has a volume of ";
    cout << volume << " cubic feet.\n";
    cheers0(cube0(2));
    
    cout<<endl;
    return 0;
}

void cheers0(int n) {
    using namespace std;
    for(int i = 0; i < n; i++)
    {
        cout << "Cheers! ";
    }
    cout << endl;
}

double cube0(double x) {

    return x * x * x;
}
