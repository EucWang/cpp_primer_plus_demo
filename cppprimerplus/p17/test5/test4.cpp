#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
// #include <list>
#include <vector>
#include "test.h"

using namespace std;

int main_p17test4(){


    string file1 = "tmp.txt";
    string file2 = "tmp2.txt";
    ofstream fout("tmp3.txt");

    char ch;
    int count  = 0;

    string tmp;
    string outstr;
    vector<string> l1;
    vector<string> l2;

    ifstream fin;
    fin.open(file1);
    if(fin.is_open()){
        while(getline(fin, tmp)) {
            l1.push_back(string(tmp));    
            tmp.clear();
        }
    }
    fin.clear();
    fin.close();
    fin.open(file2);
    if(fin.is_open()) {
       while(getline(fin, tmp)) {
            l2.push_back(string(tmp));
            tmp.clear();
        }
    }
    fin.close();

    for(int i=0; i<l1.size() || i < l2.size(); i++) {
        cout << "looper : " << i << endl;
        string outstr;
        if(i < l1.size()) {
            outstr += l1[i];
            outstr += " ";
        }
        if(i < l2.size()) {
            outstr += l2[i];
            outstr += '\n';
        }
        cout << "outstr : " << outstr << endl;
        fout.write(outstr.c_str(), outstr.size());
    }
    fout.close();

    cout << "Done!\n";
    return 0;
}