#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stacktp1.h" 

const int NUM = 10;

using std::srand;
using std::time;
using std::cout;
using std::cin;
using std::endl;


int main112() {

    srand(time(0));
    cout << "Please enter stack size : ";
    int stacksize;

    cin >> stacksize;
    Stack<const char *> st = Stack<const char *>(stacksize);  //构造栈对象

    const char * in[NUM] = {
        "1 : Hank Gilgamesh",
        "2 : Kiki Ishtar",
        "3 : Betty Rocker",
        "4 : Ian Flagranti",
        "5 : Wolfgang Kibble",
        "6 : Portia Koop",
        "7 : Joy Almondo",
        "8 : Xaverie Paprika",
        "9 : Juan Moore",
        "10 : Misha Mache"
    };

    const char * out[NUM];

    int processed = 0;
    int nextin = 0;
    while(processed < NUM) {
        if(st.isempty()) {
            st.push(in[nextin++]);
        } else if( st.isfull()) {
            st.pop(out[processed++]);
        } else if( rand() % 2 && nextin < NUM) {
            st.push(in[nextin++]);
        } else {
            st.pop(out[processed++]);
        }
    }
    for(int i=0; i<NUM; i++) {
        cout << out[i] << endl;
    }

    cout << "Bye.\n";
    return 0;
}