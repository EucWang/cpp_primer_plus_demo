#include <iostream>
#include "cd.h"

using namespace std;

void bravo(const Cd & disk);

int main123() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

    Cd * pcd = &c1;

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
    Classic copy;
    copy = c2;
    copy.report();

    return 0;
}


void bravo(const Cd & disk) {
    disk.report();
}