//getinfo.cpp -- input and output

#include <iostream>

int main175()
{
    using namespace std;

    int carrots;

    cout << "How many carrots do you have?" << endl;

    cin >> carrots;

    cout << "Here are two more.";

    carrots +=2;

    cout << "Now you have " << carrots << " carrots." << endl;

    cin.get();
    return 0;
}