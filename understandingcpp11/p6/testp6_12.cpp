#include <iostream>
#include <stdexcept>

#include "test6.h"
using namespace std;

void Printf(const char * s) {
    while(*s) {
        if(*s == '%' && *++s != '%') {
            throw runtime_error("invalid format string: missing arguments");
        }
        cout << *s++;
    }
}

template <typename T, typename...Args>
void Printf(const char* s, T value, Args... args) {
    while(*s) {
        if(*s == '%' && *++s != '%') {
            cout << value;
            return Printf(++s, args...);
        }
        cout << *s++;
    }
    throw runtime_error("extra arguments provided to Printf");
}

void testp6_12(){
    cout << __func__ << "() called.\n";
    Printf("Hello %s\n", string("world"));
    
    cout << __func__ << "() called.done.\n";
}