#include <iostream>
#include "useless.h"

int Useless::ct = 0;

//默认构造函数
Useless::Useless() {
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    showObject();
}

Useless::Useless(int k) : n(k){

    ++ct;
    pc = new char[n];
    cout << "int constructor called; number of objects: " << ct << endl;
    showObject();
}

Useless::Useless(int k, char ch) :n(k){

    ++ct;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = ch;
    }
    cout << "int, char constructor called; number of objects: " << ct << endl;
    showObject();
}

Useless::Useless(const Useless &f) :n(f.n){
    ++ct;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = f.pc[i];
    }
    cout << "copy const called; number of objects: " << ct << endl;
    showObject();
}

Useless::Useless(Useless &&f):n(f.n) {
    ++ct;
    pc =  f.pc;
    cout << "copy const called; number of objects: " << ct << endl;
    showObject();

    f.pc = nullptr;
    f.n = 0;
}

Useless::~Useless() {
    cout << "destructor called; object left: " << --ct <<endl;
    cout << "deleted object:\n";
    showObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless &f) const {
    cout  << "------Entering operator+()--------\n";
    Useless temp = Useless(n + f.n);
    for(int i=0; i<n; i++) {
        temp.pc[i] = pc[i];
    }
    for(int i=n; i< temp.n; i++) {
        temp.pc[i] = f.pc[i - n];
    }

    cout << "temp object:\n";
    cout << "--------Leaving operator+()--------\n";
    return temp;
}

void Useless::showObject() const {
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *)pc << endl;
}

void Useless::showData() const {
    if(n == 0) {
        cout << "(Object empty)";
    } else {
        for(int i=0; i<n ;i++) {
            cout << pc[i];
        }
    }
    cout << endl;
}

/**
 * 复制运算符
 * @param f  const Useless &
 * @return  Useless &
 */
Useless & Useless::operator=(const Useless &f) {
    std::cout << "copy assigment operator called:\n";
    if(this == &f) {
        return *this;
    }

    delete [] pc;
    n = f.n;
    pc = new char[n];

    for(int i=0; i<n ;i++) {
        pc[i] = f.pc[i];
    }

    return *this;
}

/**
 * 移动操作运算符
 *
 */
Useless& Useless::operator=(Useless &&f) {
    std::cout << "move assignment operator called.\n";
    if(this == &f) {
        return *this;
    }
    delete [] pc;
    n = f.n;
    pc = f.pc;

    f.n = 0;
    f.pc = nullptr;
    return *this;
}