#include <iostream>
#include "person.h"

using namespace std;


int main272()
{
    
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");


    cout << endl;
    one.show();
    cout << endl;
    one.formal_show();

    cout << endl;
    two.show();
    cout << endl;
    two.formal_show();

    cout << endl;
    three.show();
    cout << endl;
    three.formal_show();
    return 0;
}
