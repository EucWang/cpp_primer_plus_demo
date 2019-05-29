#include <iostream>
#include "tvfm.h"

int main_tv2(){
    using std::cout;
    Tv2 s42;
    cout << "Initial settings for 42 'TV'\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.settings();

    Remote2 grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);    
    grey.volup(s42);
    cout << "\ns42 settings after using remote:\n";
    s42.settings();

    Tv2 s58(Tv2::ON);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n s58 settings:\n";
    s58.settings();

    return 0;
}