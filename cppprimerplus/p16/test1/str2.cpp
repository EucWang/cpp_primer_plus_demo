#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "str1.h"

using namespace std;

/**
 * 16.2 strfile.cpp
 */ 
int main_str2(){

    ifstream fin;
    fin.open("../p16/test1/tobuy.txt");
    if((fin.is_open()) == false) {
        cerr << "Can't open file.Bye.\n";
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;
    getline(fin, item, ':');  //第三个参数必须是字符，不能是字符串
    while(fin) {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }

    cout << "Done!\n";
    fin.close();
    return 0;
}