#include <iostream>
#include "golf.h"
using namespace std;


int main273()
{
    Golf ann("Ann Birdfree", 24);
    ann.showgolf();

    Golf andy;
    int retval = andy.setgolf();
    const char * retval_str;
    if(retval){
        retval_str = "set fullname success.\n";
    }else {
        retval_str = "set fullname fail.\n";
    }
    cout << retval_str << endl;
    andy.showgolf();
    cout << ">>>>Change handicap of andy to 100.\n";
    andy.handicap(100);
    andy.showgolf();
    return 0;
}
