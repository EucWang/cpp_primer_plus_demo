#include <iostream>
#include "worker0.h"

using std::cout;
using std::endl;

const int LIM = 4;

int main114() {
    Waiter0 bob("Bob Apple", 314L, 5);
    Singer0 bev("Beverly Hills", 522L, 3);
    Waiter0 w_temp;
    Singer0 s_temp;

    Worker0 * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};

    int i;
    for(i=2; i<LIM; i++) {
        pw[i]->set();
    }
    for(i = 0; i<LIM; i++) {
        pw[i]->show();
        cout << endl;
    }

    return 0;
}
