#include "student.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main119() {

    Student ada[pupils] = {
        Student(quizzes), Student(quizzes), Student(quizzes)
    };

    int i;
    for(i = 0; i<pupils; ++i) {
        set(ada[i], quizzes);
    }
    cout << "\nStudent List:\n";
    for(i =0; i<pupils; ++i) {
        cout << ada[i].getName() << endl;
    }
    cout  << "\nResults:";
    for(i=0; i<pupils; ++i) {
        cout << endl << ada[i];
        cout << "average : " << ada[i].average() << endl;
    }
}

void set(Student & sa, int n) {
    cout << "Please enter the student's name:";
    getline3(cin ,sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for(int i =0; i<n; i++) {
        cin >> sa[i];
    }
    while(cin.get() != '\n') {
        continue;
    }
}