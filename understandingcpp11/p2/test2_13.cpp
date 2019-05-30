#include <iostream>

using namespace std;

/**
 * 默认情况下， c++11标准让类的析构函数也是noexcept(true)的，
 * 即如果 析构函数抛出异常，则会导致程序终止，
 * 
 * 
 */ 
struct A{
    ~A(){throw 1;}
};

struct B{
    ~B() noexcept(false) { throw 2;}
};

struct C{
    B b;
};

int funA(){
    A a;
    return 1;
}

int funB(){
    B b;
    return 1;
}

int funC() {
    C c;
    return 1;    
}

int testp2_13(){

    try{
        funB();
    }catch(...){
        cout << "caught funB." << endl;
    }

    try{
        funC();
    }catch(...) {
        cout << "caught funC." << endl;
    }

    try{
        funA();
    }catch(...){
        cout << "Caught funA." << endl;
    }

    return 0;
}