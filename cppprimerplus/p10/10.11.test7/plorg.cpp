#include <iostream>
#include "plorg.h"
#include <cstring>

using namespace std;

Plorg::Plorg(const char * name, int ci) {
    strncpy(mName, name, 20);
    mCI = ci;
}

void Plorg::set_ci(int ci) {
    mCI = ci;
}

void Plorg::show() const {
    cout << "\n====Plorg info====\n";
    cout << "name : " << mName << " , ci : " << mCI << endl;
}