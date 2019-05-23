#include "test2.h"
#include <iostream>

#include "useless.h"


/**
 * 18.2
 *
 * @return
 */
int main_useless(){

    {
        Useless one(10, 'x');
        Useless two = one;
        Useless three(20, 'o');
        Useless four (one + three);

        cout << "object one : ";
        one.showData();

        cout << "object two : ";
        two.showData();

        cout << "object three : ";
        three.showData();

        cout << "object four : ";
        four.showData();

    }

    return 0;
}