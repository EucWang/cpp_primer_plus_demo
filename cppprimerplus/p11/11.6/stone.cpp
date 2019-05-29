#include <iostream>
#include "stonewt.h"

using std::cout;

void display(const Stonewt & st, int n);

int main97(){

    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();

    cout << "The detective weighed ";
    wolfe.show_stn();

    cout << "The president weighed ";
    taft.show_lbs();

    incognito = 276.8;
    taft = 325;
    cout << "After dinner, the celebrity weighed ";
    taft.show_lbs();

    display(taft, 2);
    cout << "The wrestler weighed even more.\n";

    //虽然函数接受的是Stonewt类型，但是这里传参是数字类型，隐式转换
    display(422, 2);
    cout << "No stone left unearned!\n";
    return 0;
}

void display(const Stonewt & st, int n) {
    for(int i=0; i<n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}