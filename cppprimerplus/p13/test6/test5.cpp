#include <iostream>
#include "cd.h"

using namespace std;

void bravo(const Cd6 & disk);

int main122() {
    Cd6 c1("Beatles", "Capitol", 14, 35.5);
    Classic6 c2 = Classic6("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

    Cd6 * pcd = &c1;

    cout << "\n<----\nUsing object directly:" << endl;
    c1.report();
    c2.report();

    cout << "\n<----\nUsing type cd * pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();

    cout <<"\n<----\nCalling a function with a Cd reference argument:\n";
    bravo(c1);
    bravo(c2);

    cout << "\n<----\nTesting assigment:";
    Classic6 copy;
    copy = c2;
    copy.report();

    return 0;
}


void bravo(const Cd6 & disk) {
    disk.report();
}