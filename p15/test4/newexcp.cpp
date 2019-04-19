#include <iostream>
#include <new>
#include <cstdlib>

#include "error.h"

using namespace std;

struct Big{
    double stuff[200000000];
};

/**
 * 对于使用new导致的内存分配问题，
 * C++ 是让new 引发bad_alloc异常，
 * 需要导入头文件： <new>  包含bad_alloc类的声明
 */ 
int main_newexcp2(){
    Big * pb;

    try{
        cout << "Trying to get a big block of memory:\n";
        pb = new Big[100000000];
        cout << "Got past the new request:\n";
    }catch(bad_alloc & ba) {   
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}

/**
 * 可以使用一个标记开关，让new返回时不抛出异常，而是返回nullptr，
 * 让用户自己选择所需的行为。
 */ 
int main_newexcp(){
    Big * pb;

    cout << "Trying to get a big block of memory:\n";
    pb = new (std::nothrow) Big[100000000];
    if(pb == nullptr){
        cout << "\nCould not allocate memory.Bye.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
