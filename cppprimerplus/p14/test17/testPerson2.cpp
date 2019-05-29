#include <iostream>
#include <cstring>

#include "person.h"

const int SIZE = 5;

using std::cin;
using std::cout;
using std::endl;
using std::strchr;

int main1417() {

    Person2 * persons[SIZE];

    int ct;
    for(ct = 0; ct < SIZE; ct++) {

        char choice;
        cout << "Enter the Person category:\n"
            << "g: Gunslinger"
            <<"\np: PokerPlayer\t b: BadDude  \nq: quit\n";
        cin >> choice;
        while( strchr("gpbq", choice) == NULL) {
            cout << "Please enter a [g, p, b or q]: ";
            cin >> choice;
        }
        if(choice == 'q') {
            break;
        }
        switch(choice) {
            case 'g' :
                persons[ct] = new Gunslinger();
                break;
            case 'p':
                persons[ct] = new PokerPlayer();
                break;
            case 'b':
                persons[ct] = new BadDude();
                break;
        }

        cin.get();
        persons[ct]->set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for(i=0; i<ct; i++) {
        cout << endl;
        // 如下问题，记得 父类的析构函数 一定要是虚的virtual，
        // cpp_primer_plus_demo(676,0x1157485c0) malloc: *** error for object 0x7f8f27d00010: pointer being freed was not allocated
        // cpp_primer_plus_demo(676,0x1157485c0) malloc: *** set a breakpoint in malloc_error_break to debug
        persons[i]->show();
    }
    cout << "\nNow release memory:";
    for(i=0; i<ct; i++) {
        delete persons[i];
    }
    cout << "bye.\n";
    return 0;
}
