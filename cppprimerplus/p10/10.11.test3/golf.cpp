#include <iostream>
#include <cstring>
#include "golf.h"

using namespace std;


Golf::Golf(const char * name, int hc){
    strcpy((*this).mFullname, name);
    mHandicap = hc;
}

int Golf::setgolf(){
    cout << "Please enter username : ";
    int result = 0;
    cin.get(mFullname, LEN);
    char tmp;
    if(cin){
        result = 1;
    }else {
        cin.clear();
    }
    cin.get(tmp);
    while(tmp != '\n')continue;

    cout << "Please enter handicap : ";
    cin >> mHandicap;
    return result;
}

void Golf::handicap(int hc){
    mHandicap = hc;
}

void Golf::showgolf() const{
    cout <<"======Golf info========" << endl
        << "FULLNAME : " << mFullname << endl
        << "HANDICAP : " << mHandicap << endl;
}