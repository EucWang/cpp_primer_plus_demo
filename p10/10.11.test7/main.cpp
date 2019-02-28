#include <iostream>
#include "plorg.h"

using namespace std;


int main()
{
    Plorg p1 = Plorg();

    cout << "default construct Plorg : " << endl;
    p1.show();

    p1.set_ci(100);
    cout << endl << " reset ci " << endl;
    p1.show();

    Plorg p2 = Plorg("PrimerPlorga", 10);
    cout << endl << "another plorg" << endl;
    p2.show();

    return 0;
}
