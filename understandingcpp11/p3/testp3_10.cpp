#include <iostream>
#include "test3.h"

using namespace std;

/**
 * 列表初始化 可以防止 类型收窄
 * 
 * 列表初始化 是唯一可以防止类型收窄的初始化方式
 */ 
void testp3_10(){
    cout << __func__ << "() called." << endl;

    const int x =1024;
    const int y = 10;
    
    char a = x;
    char * b = new char(1024);
    // char c = {x};//不能通过编译
    
    char d = {y};
    // unsigned char e{-1};  //不能通过编译
    float f{7};

    // int g{2.0f};
    // float * h = new float {1e48};//不能通过编译
    float i = .2l;


    cout << __func__ << "() called. done." << endl;
}