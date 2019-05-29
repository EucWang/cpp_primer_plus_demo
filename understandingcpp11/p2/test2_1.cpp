#include <iostream>
#include "test2.h"


using namespace std;


void testp2_1(){
    cout << "Standard Clib : " << __STDC_HOSTED__ << endl; 

    cout << "Standard C: " << __STDC__ << endl;

    // cout << "C Stardard version : " << __STDC_VERSION__ << endl;  没有这个宏定义
    // cout << "ISO/IEC " << __STDC__ISO_10646__ << endl;   也没有这个宏定义
}