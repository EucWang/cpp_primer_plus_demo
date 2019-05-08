//
// Created by 王新年 on 2019-05-03.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int test3in16(){

    vector<string> retVal;

    ifstream fin;
    fin.open("../p16/test1/tobuy.txt");
    if(!fin.is_open()) {
        cerr << "open file fail,exit\n";
        return -1;
    }

    int count = 0;
    string tmp;
    getline(fin, tmp, ':');
    while(fin) {
        retVal.push_back(tmp);
        getline(fin, tmp, ':');
    }

    cout << endl << "result is :\n";
    for(int i=0; i<retVal.size(); i++) {
       cout <<  retVal[i] << "\t";
    }

    return 0;
}