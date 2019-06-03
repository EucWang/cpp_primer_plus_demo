#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <initializer_list>   //initialize_list类模板

#include "test3.h"

using namespace std;

enum Gender{boy, girl};

/**
 * 自定义类， 接收 初始化列表作为入参
 */ 
class People{
private:
    vector<pair<string, Gender>> data;
public:
    People(initializer_list<pair<string, Gender>> l) {
        auto i = l.begin();
        for(; i != l.end(); ++i) {
            data.push_back(*i);
        }
    }
    void show(){
        for_each(data.begin(), data.end(), [](pair<string, Gender> & it){cout<<it.first << ", " << it.second << endl;});
    }
};

/**
 * 自定义函数也可以接收 初始化列表
 */ 
void fun38(initializer_list<int> iv){
    cout << __func__ << "() called.\n";
}

void testp3_8(){
    cout << __func__ << "() called.\n";

    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};

    vector<int> c{1, 3, 5};

    map<int, float> d = {
        {1, 1.0f},
        {2, 2.0f},
        {5, 5.0f}
    };


    People p({{"Garfield", boy},
        {"HelloKitty", girl},
        {"Tom", boy} });

    p.show();

    fun38({1,3});
    fun38({});

    cout << __func__ << "() called done.\n";
}