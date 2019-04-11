#include "cd.h"
#include <iostream>
#include <cstring>

using namespace std;

//================= Cd6 ========================

Cd6::Cd6() {
    performers = new char[1];
    performers[0] = '\0';

    label = new char[1];
    label[0] = '\0';

    selections = 0;
    playtime = 0;
}

Cd6::Cd6(char * s1, char * s2, int n, double x){

    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);


    label = new char[strlen(s2) + 1];
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd6::Cd6(const Cd6 & d) {

    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);

    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}


void Cd6::report() const {
    cout << "\nCd6\t"
        << "\nPerformers: " << performers
        << "\nLabel: " << label 
        << "\nSelections: " << selections
        << "\nPlaytime: " << playtime;
}

Cd6 & Cd6::operator=(const Cd6 & d) {
    if(this != &d) {
        delete [] performers;
        delete [] label;

        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);

        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);

        selections = d.selections;
        playtime = d.playtime;
    }

    return *this;
}

Cd6::~Cd6(){
    delete [] performers;
    delete [] label;
}

//================= Classic ========================

/**
 *  默认构造函数
 */ 
Classic6::Classic6()
    : Cd6() {
    major = new char[1];
    major[0] = '\0';
}

/**
 * 全参数构造函数 
 */
Classic6::Classic6(char * m, char * s1, char * s2, int n, double x)
    :Cd6(s1, s2, n, x) {

    major = new char[strlen(m) + 1];
    strcpy(major, m);
}

/**
 * 复制构造函数
 */ 
Classic6::Classic6(const Classic6 & c)
    :Cd6((Cd6 &)c) {

    major = new char[strlen(c.major) + 1];
    strcpy(major, c.major);   
}

/**
 * 赋值运算符
 */ 
Classic6 & Classic6::operator=(const Classic6 & c) {
    if( this != &c) {
        Cd6::operator=(c);
        delete [] major;
        major = new char[strlen(c.major) + 1];
        strcpy(major, c.major);   
    }
    return *this;
}

void Classic6::report() const {
     cout << "\nClassic6======" ;
     Cd6::report();
     cout << "\nMajor: " << major << endl;
}