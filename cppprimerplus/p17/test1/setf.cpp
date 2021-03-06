#include <iostream>

/**
 * 17.8
 * using setf() to control formatting
 */ 
int main_setf(){

    using namespace std;

    int temperature = 63;
    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);
    cout << temperature << endl;

    cout << "For our programming friends, that's \n";
    cout << std::hex << temperature << endl;
    cout.setf(ios_base::uppercase);  // using  uppercase in hex
    cout.setf(ios_base::showbase);  // use ox prefix for hex
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "! oops -- How ";

    
    cout.setf(ios_base::boolalpha);
    cout << true <<"!\n";

    return 0;
}