#include <iostream>
#include "test8.h"

using namespace std;

void testp8_20(){
    cout << __func__ << "() called.\n";
    
    cout << R"(hello, \n
            world)" << endl;

    cout << u8R"(\u4F60, \n 
            \u597D)" << endl;

    cout << u8R"(你好)"  << endl;

    cout << sizeof(u8R"(hello)") << "\t" << u8R"(hello)" << endl;
    cout << sizeof(uR"(hello)") << "\t" << uR"(hello)" << endl;
    cout << sizeof(UR"(hello)") << "\t" << UR"(hello)" << endl;
        
    cout << __func__ << "() called.done.\n";
}