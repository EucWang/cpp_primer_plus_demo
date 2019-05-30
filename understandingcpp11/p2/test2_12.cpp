#include <iostream>

using namespace std;

void Throw() {throw 1;}

void noBlockThrow(){Throw();}

/**
 * noexcept标注的方法如果抛出了异常，那么程序会自动终止
 * 即使方法位于try.catch. 块中，依然不会捕获异常，而是直接终止
 */ 
void blockThrow() noexcept {Throw();}

int testp2_12(){

    try{
        Throw();
    }catch(...){
        cout << "Found throw." << endl;
    }

    try{
        noBlockThrow();
    }catch(...){
        cout << "Throw is not blocked." << endl;
    }

    try{
        blockThrow();
    }catch(...){
        cout << "Found Throw 1. " << endl;
    }

    return 0;
}