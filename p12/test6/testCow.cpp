#include <iostream>
#include "cow.h"

int main(){

    const char * hobby = "eat wet";
    const char * hobby2 = "eat very more wet";
    Cow a("big cow", hobby , 100.0);
    a.showCow();

    Cow b("big big bbbbbbbbbbbbig cow", hobby2, 200.0);
    a = b;
    a.showCow();

    return 0;
}