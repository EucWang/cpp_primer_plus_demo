#include <iostream>
#include <sstream>
#include <string>

#include "test4.h"

int main_strin2(){

    using namespace std;
    string lit = "It was a dark and stormy day, and " 
            "the full moon glowed brilliantly. ";
    istringstream instr(lit);
    string word;  
    while(instr >> word) {  //会一个单词一个单词的输出
        cout << word << endl;
    }

    return 0;
}