#include <iostream>
#include "test2.h"
using namespace std;

struct People{
    public:
        int hand;
        static People * all;
};

/**
 * 非静态成员的sizeof
 * 在C++11中，通过类方式查看类的非静态成员的sizeof是可以通过编译的
 */ 
int testp2_18(){

    People p;
    cout << "sizeof(p.hand) : " << sizeof(p.hand) << endl;
    cout << "sizeof(People::all) : " << sizeof(People::all) << endl;
    cout << "sizeof(People::hand) : " << sizeof(People::hand) << endl;  //在C++98中编译不通过
    cout << "sizeof(((People *)0)->hand) : " << sizeof(((People *)0)->hand) << endl; //如果在C++98中可以采用如下方式
 
    return 0;
}