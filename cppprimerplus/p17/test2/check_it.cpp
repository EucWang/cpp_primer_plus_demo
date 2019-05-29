#include <iostream>

/**
 * 17.11 
 * check_it.cpp
 * checking for valid input
 */ 
int main_check_it(){

    using namespace std;
    cout << "Enter numbers: ";

    int sum=0;
    int input;
    while(cin >> input) {
        sum += input;
    }
    
    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}