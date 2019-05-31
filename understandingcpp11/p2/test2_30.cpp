#include <iostream>
#include "test2.h"

/**
 * 模板类
 */ 
template <class T> class X{

};

/**
 * 模板函数
 */ 
template <class T>
void TempFun(T t){

};

// 结构体
struct A{
} a;

struct {int i; } b;  //匿名结构体变量

typedef struct {int i; } B; // B是匿名类型

template <class T>
struct MyTemplate{

};

int testp2_30(){

    struct  C {} c; 

    // A 是普通全局变量，可以作为模板类型参数
    X<A> x1;
    //B是匿名结构体变量
    X<B> x2;
    //C是局部结构体变量， 依然可以作为模板类型参数
    X<C> x3;

    //同理，  a，b，c ,分别是 全局变量， 匿名结构体变量， 局部结构体变量，
    //都可以作为模板类型参数，
    TempFun(a);
    TempFun(b);
    TempFun(c);

    //虽然可以将匿名变量作为模板参数，但是匿名类型的声明不能在模板实参位置
    //即使是匿名的结构体的声明，也需要单独的表达式语句，
    //error: cannot be defined in a type specifier
    // MyTemplate<struct {int a;}> t;

    std::cout <<"testP2_30()\n";

    return 0;
}