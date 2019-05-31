#include <iostream>
#include "test2.h"

using namespace std;

void defParam(int m = 3){}

/**
 * 指定模板类的默认模板参数类型
 */ 
template <typename T = int>
class DefClass{

};

/**
 * 指定模板方法的默认模板参数类型
 */ 
template <typename T = int>
void defTempParam(){
}

template <typename T1, typename T2= int>
class DefClass1{

};

/**
 * 如下的类模板，需要按照 从右往左 的顺序指定模板参数默认值，否则不能通过编译
 */ 
// template <typename T1 = int, typename T2>
// class DefClass2{
// };

template <class T, int i=0>
class DefClass3{

};

/**
 * 如下的类模板，需要按照 从右往左 的顺序指定模板参数默认值，否则不能通过编译
 */ 
// template <int i=0, typename T>
// class DefClass4{
// };

/**
 * 函数模板的默认模板参数类型，则不需要按照 “从右往左”的顺序指定
 */ 
template<typename T1= int, typename T2>
void defFunc1(T1 a, T2 b);

template<int i=0, typename T>
void defFunc2(T a);

template <class T, class U = double>
void f(T t=0, U u = 0) {

}

void g(){
    f(1, 'c');
    f(1);   //第二个模板参数类型使用默认模板参数类型
    // f();   //这个不能通过编译，因为不能推导出模板参数类型
    f<int>();
    f<int, char>();
}


int testp2_27(){
    cout << "testp2_27" << endl;
    g();
    return 0;
}