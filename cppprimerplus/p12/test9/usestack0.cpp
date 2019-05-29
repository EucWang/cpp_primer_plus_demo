#include <iostream>
#include "stack0.h"

using namespace std;


int main128() {

    Stack a(10);
    Stack b(20);

    a.push(10);
    a.push(19);
    a.push(18);
    a.push(17);
    a.push(16);
    cout << "stack a :\n" << a << endl;

    b = a;
    b.push(15);
    cout << "stack b :\n" << b << endl;

    Stack c = b;
    Item temp;
    c.pop(temp);
    cout << "pop up from c value : " << temp << endl;
    c.pop(temp);
    cout << "pop up from c value : " << temp << endl;
    c.pop(temp);
    cout << "pop up from c value : " << temp << endl;

    cout << "after that c is " << c << endl;
    cout << "but a is " << a << endl;
    cout << "and b is " << b << endl;

    return 0;
}
