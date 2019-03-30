#include "worker0.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//--------------Worker-------------------------

Worker::~Worker(){}

void Worker::set() {
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter Worker's Id : ";
    cin >> id;
    while(cin.get() != '\n') {
        continue;
    }
}

void Worker::show() const {
    cout << "Name : " << fullname << endl;
    cout << "Employee ID : " << id << endl;
}

//--------------Waiter-------------------------

void Waiter::set() {
    Worker::set();
    cout << "Enter waiter's panache rating : ";
    cin >> panache;
    while( cin.get() != '\n') {
        continue;
    }
}

void Waiter::show() const {
    cout << "Category : waiter\n";
    Worker::show();
    cout << "Panache rating : " << panache << endl;
}

//--------------Singer-------------------------

char * Singer::pv[] = {"other", "alto", "contralto", "soprano", 
                        "bass", "baritone", "tenor"};

void Singer::set() {
    Worker::set();
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for( i=0; i<Vtypes; i++) {
        cout << i << ": " << pv[i] << '\t';
        if(i%4 == 3) {
            cout << endl;
        }
    }

    if(i%4 != 0) {
        cout << endl;
    }

    while(cin >> voice && (voice < 0 || voice >= Vtypes)) {
        cout << "Please enter a value >=0 and < " << Vtypes << endl;
    }

    while(cin.get() != '\n') {
        continue;
    }
}

void Singer::show() const {
    cout << "Category: singer\n";
    Worker::show();
    cout << "Vocal range: " << pv[voice] << endl;
}