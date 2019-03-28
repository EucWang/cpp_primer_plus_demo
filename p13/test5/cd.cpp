#include "cd.h"
#include <iostream>
#include <cstring>

using namespace std;

//================= Cd ========================

Cd::Cd() {
    for(int i=0; i<50; i++) {
        performers[i] = '\0';
    }

    for(int i=0; i<20; i++) {
        label[i] = '\0';
    }

    selections = 0;
    playtime = 0;
}

Cd::Cd(char * s1, char * s2, int n, double x){
    strncpy(performers, s1, 49);
    performers[49] = '\0';

    strncpy(label, s2, 19);
    performers[19] = '\0';

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {
    strcpy(performers, d.performers);
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}


void Cd::report() const {
    cout << "\nCd\t" 
        << "\nPerformers: " << performers
        << "\nLabel: " << label 
        << "\nSelections: " << selections
        << "\nPlaytime: " << playtime;
}

Cd & Cd::operator=(const Cd & d) {
    if(this != &d) {
        strcpy(performers, d.performers);
        strcpy(label, d.label);

        selections = d.selections;
        playtime = d.playtime;
    }

    return *this;
}

//================= Classic ========================

Classic::Classic(char * m, char * s1, char * s2, int n, double x)
    :Cd(s1, s2, n, x) {
        strncpy(major, m, 99);
        major[99] ='\0';
}

// Classic::Classic(const Classic & c) {}
// Classic::Classic(char * m, const Classic & c) {}

Classic::Classic()
    : Cd() {

    for(int i=0; i<100; i++) {
        major[i] = '\0';
    }
}

void Classic::report() const {
     cout << "\nClassic======" ;
     Cd::report();
     cout << "\nMajor: " << major << endl;
}