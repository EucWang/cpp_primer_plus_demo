
#include <iostream>
#include <string>

#include "test.h"

using namespace std;

int main_p17test1(){

    int count = 0;
    char ch;
    char tmp;
    while( (tmp = cin.peek()) != '$') {
        cin.get(ch);
        count++;
    }
    cout << "count is " << count << endl;
    cout << "next character is " << tmp << endl;

    return 0;
}