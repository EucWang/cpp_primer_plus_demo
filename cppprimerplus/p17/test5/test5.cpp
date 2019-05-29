#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <iterator>
#include "test.h"

using namespace std;

vector<string> getFriends(const char * who);

int main_p17test5(){

    vector<string> mat = getFriends("mat.dat");

    vector<string> pat = getFriends("pat.dat");

    cout << "===================\n";
    showVector2("Pat's all friends here: ", mat);
    cout << "===================\n";
    showVector2("Mat's all friends here: ", pat);
    cout << "===================\n";

    vector<string> all;
    copy(mat.begin(), mat.end(), insert_iterator<vector<string>>(all, all.begin()));
    copy(pat.begin(), pat.end(), insert_iterator<vector<string>>(all, all.begin()));
    sort(all.begin(), all.end());
    unique(all.begin(), all.end());
    showVector2("Mat and Pat's all friends here: ", all);

    ofstream fout("matnpat.dat");
    if(fout.is_open()) {
        // for_each(auto it = all.begin(); it != all.end(); it++) {
        //     fout.write(*it, (*it).size());
        // }
        for(int i=0; i<all.size(); i++) {
              fout.write(all[i].c_str(), all[i].size());
              fout.write("\n",1);
        }
    }
    fout.close();
    return 0;
}

vector<string> getFriends(const char * who) {
    unique_ptr<vector<string>> retVal(new vector<string>);
    ifstream fin(who);
    if(fin.is_open()) {
        string tmp;
        while(getline(fin, tmp)){
            if(tmp.size() <= 0) {
                break;
            }
            retVal->push_back(tmp);
        }
    }
    fin.close();
    sort(retVal->begin(), retVal->end());
    return *retVal;


    // unique_ptr<vector<string>> tmp(new vector<string>);
    // cout << "enter "  << who << "'s friends : " << endl;
    // while(true) {
    //     string f;
    //     getline(cin, f);
    //     if(f.size() == 0) {
    //         break;
    //     }
    //     tmp->push_back(f);
    //     cout  << "more friend : " ;
    // }

    // sort(tmp->begin(), tmp->end());
    // return *tmp;
}