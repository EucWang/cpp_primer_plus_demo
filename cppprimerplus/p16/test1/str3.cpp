// 16.4 str2.cpp capacity()  and reserve()  and c_str() 

#include <iostream>
#include <string>
#include <fstream>

#include "str1.h"

using namespace std;

int main_str3() {

    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend.";

    cout << "Size:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall:" << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;

    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "
        << empty.capacity() << endl;



    // string filename;
    // cout << "Enter file name : ";
    // cin >> filename;
    // ofstream fout;
    // fout.open(filename.c_str());


    return 0;
}