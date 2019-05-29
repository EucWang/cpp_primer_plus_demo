#include <iostream>
#include "emp.h"

using namespace std;

int main_emp(){

    employee em("Trip", "Harris", "Thumper");
    cout << em << endl << endl;

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.showAll();
    cout << endl<< endl;

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.showAll();
    cout << endl<< endl;

    highfink hf(ma, "Curly Kew");
    hf.showAll();
    cout << endl<< endl;

    cout << "Press a key for next phase:\n";
    cin.get();
    while(cin && cin.get() != '\n') {
        continue;
    }

    highfink hf2;
    hf2.setAll();
    cout << endl<< endl;

    cout << "Using an abstr_emp * pointer:\n";
//    abstr_emp tri[4] = {em, fi, hf, hf2};
//    for(int i=0; i<4; i++) {
//        tri[i].showAll();
//        cout << endl;
//    }
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for(int i=0; i<4; i++) {
        tri[i] ->showAll();
        cout << endl;
    }
    return 0;
}

