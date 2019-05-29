#include <iostream>
#include <sstream>
#include <string>

#include "test4.h"

/**
 * 17.21 strout.cpp
 * 
 * 头文件
 * sstream
 * 
 * 新的对象
 * ostringstream  可将数据写如其中，然后可以生成string对象
 * 
 * 
 */ 
int main_strout(){

    using namespace std;
    ostringstream outstr;
    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;
    outstr << "The hard disk " << hdisk << " has a capacity of "
            << cap << " gigabytes.\n";
    string result = outstr.str();
    cout << result;
    return 0;
}