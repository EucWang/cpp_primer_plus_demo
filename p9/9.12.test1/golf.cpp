#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;

void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g){
    cout << "Please enter username : ";
    int result = 0;
    cin.get(g.fullname, LEN);
    char tmp;
    if(cin){
        result = 1;
    }else {
        cin.clear();
    }
    cin.get(tmp);
    while(tmp != '\n')continue;

    cout << "Please enter handicap : ";
    cin >> g.handicap;
    return result;
}

void handicap(golf & g, int hc){
    g.handicap = hc;
}

void showgolf(const golf & g){
    cout <<"======Golf info========" << endl
        << "FULLNAME : " << g.fullname << endl
        << "HANDICAP : " << g.handicap << endl;
}