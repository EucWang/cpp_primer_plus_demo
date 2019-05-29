#include <iostream>
#include <cstring>

#include "test1.h"


using namespace std;

/**
 * 17.1 write.cpp
 * using cout.write()
 */ 
int main_write(){

    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";

    int len = strlen(state2);

    cout << "Increasing loop index:\n";
    for(int i=1; i<=len; i++) {
        cout.write(state2, i);
        cout << endl;
    }

    cout << "Decreasing loop index:\n";
    for(int i=len; i>0;i--) {
        cout.write(state2, i)
            << endl;
    }

    cout << "Exceeding string length:\n";
    cout.write(state2, len+5) << endl;

    cout << "show long \n";
    long val = 560031841;
    cout.write((char *)&val, sizeof(long))
    << endl;

    return 0;
}