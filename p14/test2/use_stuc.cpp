#include "student.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void set2(Student2 & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main115() {

    Student2 ada[pupils] = {
        Student2(quizzes), Student2(quizzes), Student2(quizzes)
    };

    int i;
    for(i = 0; i<pupils; ++i) {
        set2(ada[i], quizzes);
    }
    cout << "\nStudent2 List:\n";
    for(i =0; i<pupils; ++i) {
        cout << ada[i].name() << endl;
    }
    cout  << "\nResults:";
    for(i=0; i<pupils; ++i) {
        cout << endl << ada[i];
        cout << "average : " << ada[i].average() << endl;
    }

    return 0;
}

void set2(Student2 & sa, int n) {
    cout << "Please enter the Student2's name:";
    getline2(cin ,sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for(int i =0; i<n; i++) {
        cin >> sa[i];
    }
    while(cin.get() != '\n') {
        continue;
    }
}