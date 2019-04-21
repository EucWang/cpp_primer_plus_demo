#include "use_tv3.h"
#include "tv3.h"

#include <iostream>

void main_tv3() {

    using std::cout;
    Tv3 s42;
    cout << "Initial settings for 42 'TV'\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.chanup();
    cout << "\nAdjusted settings for 42 'TV'\n";
    s42.settings();

    Remote3 grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);    
    grey.volup(s42);
    cout << "\ns42 settings after using remote:\n";
    s42.settings();

    Tv3 s58(Tv3::ON);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n s58 settings:\n";
    s58.settings();

    cout << "\n-----------------\n";
    s58.buzz(grey);
    grey.showBuzz();
    cout << "\n-----------------change again\n";
    s58.buzz(grey);
    grey.showBuzz();

}