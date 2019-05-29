/**
 * 检测字符串是否是回文
 */ 

#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "test16.h"

using namespace std;

bool isPhraseStr(string & str){
    string::iterator a = str.begin();
    string::reverse_iterator b = str.rbegin();

    bool retVal = true;
    for(; (a != str.end()) || (b != str.rend()); a++, b++) {
        if(*a != *b) {
            retVal = false;
            break;
        }
    }
    return retVal;
}

int main_test1in16(){
    string tmp;

    while(true){
        cout << "请输入一个英语字符串，我们来判断这个是不是回文,输入空字符串结束\n";
        getline(cin, tmp);
        if(tmp.size() == 0) {
            break;
        }
        cout << tmp;
        if(isPhraseStr(tmp)) {
            cout << "是回文";
        }else {
            cout << "不是回文";
        }
        cout << endl;
    }

    cout << "ByeBye!!\n";
    return 0;
}