#include <iostream>
#include "test3.h"
using namespace std;

struct A {
    A(int i):i(i){}
    A(double d, int i):d(d),i(i){}
    A(float f, int i, const char * c):f(f),i(i),c(c) {}

    int i;
    double d;
    float f;
    const char * c;
};

struct B : A{
    //在c++11中，不需要这么麻烦，写这么多透传的构造函数
    // B(int i) : A(i), d(i){}
    // B(double d, int i) : A(d, i) {}
    // B(float f, int i, const char * c): A(f, i, c) {}
    using A::A; //直接继承A的构造函数，不用写 透传的构造函数，而且是隐式声明的，这一句都可以省掉
    int e{0}; //

    virtual void extraInterface(){}
};

struct Base{
    void f(double i) {cout << "Base : " << i << endl; }
};

struct Derived : Base {
    using Base::f; //使用Base基类中参数是double的f函数
    void f( int i) {cout << "Derived: "<< i << endl;}
};


void testp3_1(){
    cout << "testp3_1()\n" << endl;

    Base b;
    b.f(4.5);

    Derived d;
    d.f(4.5);  //依然会调用基类的版本

    B bb(9.9, 356);
    cout << "B.e = " << bb.e << endl;
    cout << "B.i = " << bb.i << endl;
}