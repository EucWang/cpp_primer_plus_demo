#include <iostream>
#include "tv.h"

int main_tv(){
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42 'TV'\n";
    s42.setting();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.setting();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);    
    grey.volup(s42);
    cout << "\ns42 settings after using remote:\n";
    s42.setting();

    Tv s58(Tv::ON);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n s58 settings:\n";
    s58.setting();

    return 0;
}