#include <iostream>
#include <string>
#include "person.h"
#include <cstring>

using namespace std;

Person::Person(const std::string & ln, const char * fn){
    (*this).lname = ln;
    strcpy((*this).fname, fn);
}

void Person::show() const {
    cout << "Person [ lname : " << lname << ", \tfname : " << fname << "]"  << endl;
}

void Person::formal_show() const {
    cout << "=====Person=======" << endl;
    cout << "lname : " << (*this).lname << endl;
    cout << "fname : " << fname << endl;
}