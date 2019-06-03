#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
#include "test3.h"

using namespace std;

class MyData {
private:
    vector<int> idx;
    vector<int> d;

public:
    MyData & operator [] (initializer_list<int> l) {
        for(auto i = l.begin(); i != l.end(); ++i) {
            idx.push_back(*i);
        }
        return *this;
    }

    MyData & operator = (int v) {
        if(!idx.empty()) {
            for(auto i = idx.begin(); i != idx.end(); ++i) {
                d.resize( (*i > d.size()) ? *i : d.size() );
                d[ *i - 1] = v;
            }
            idx.clear();
        }
        return *this;
    }

    void show(){
        for(auto i = d.begin(); i!= d.end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }
};


void testp3_9(){
    cout << __func__ << "() called.\n";

    MyData d;
    d[{2, 3, 5}] = 7;
    d.show();
    d[{1,4,5,8}] = 4;
    d.show();

    cout << __func__ << "() called done.\n";
}