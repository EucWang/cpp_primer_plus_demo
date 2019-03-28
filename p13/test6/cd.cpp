#include "cd.h"
#include <iostream>
#include <cstring>

using namespace std;

//================= Cd ========================

Cd::Cd() {
    performers = new char[1];
    performers[0] = '\0';

    label = new char[1];
    label[0] = '\0';

    selections = 0;
    playtime = 0;
}

Cd::Cd(char * s1, char * s2, int n, double x){

    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);


    label = new char[strlen(s2) + 1];
    strcpy(label, s2);

    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {

    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);

    label = new char[strlen(d.label) + 1];
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

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

//================= Classic ========================

/**
 *  默认构造函数
 */ 
Classic::Classic()
    : Cd() {
    major = new char[1];
    major[0] = '\0';
}

/**
 * 全参数构造函数 
 */
Classic::Classic(char * m, char * s1, char * s2, int n, double x)
    :Cd(s1, s2, n, x) {

    major = new char[strlen(m) + 1];
    strcpy(major, m);
}

/**
 * 复制构造函数
 */ 
Classic::Classic(const Classic & c) 
    :Cd((Cd &)c) {

    major = new char[strlen(c.major) + 1];
    strcpy(major, c.major);   
}

/**
 * 赋值运算符
 */ 
Classic & Classic::operator=(const Classic & c) {
    if( this != &c) {
        Cd::operator=(c); 
        delete [] major;
        major = new char[strlen(c.major) + 1];
        strcpy(major, c.major);   
    }
    return *this;
}

void Classic::report() const {
     cout << "\nClassic======" ;
     Cd::report();
     cout << "\nMajor: " << major << endl;
}