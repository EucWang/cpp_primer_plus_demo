#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "test16.h"

using namespace std;

vector<string> getFriends(const char * who);

int test8in16(){

    vector<string> mat = getFriends("Mat");

    vector<string> pat = getFriends("Pat");

    cout << "===================\n";
    showVector("Pat's all friends here: ", mat);
    cout << "===================\n";
    showVector("Mat's all friends here: ", pat);
    cout << "===================\n";

    vector<string> all;
    copy(mat.begin(), mat.end(), insert_iterator<vector<string>>(all, all.begin()));
    copy(pat.begin(), pat.end(), insert_iterator<vector<string>>(all, all.begin()));
    sort(all.begin(), all.end());
    unique(all.begin(), all.end());
    showVector("Mat and Pat's all friends here: ", all);

    return 0;
}

vector<string> getFriends(const char * who) {
    unique_ptr<vector<string>> tmp(new vector<string>);
    cout << "enter "  << who << "'s friends : " << endl;
    while(true) {
        string f;
        getline(cin, f);
        if(f.size() == 0) {
            break;
        }
        tmp->push_back(f);
        cout  << "more friend : " ;
    }

    sort(tmp->begin(), tmp->end());
    return *tmp;
}