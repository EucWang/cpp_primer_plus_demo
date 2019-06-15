#include <iostream>
#include <memory>

#include "test8.h"

using namespace std;

struct HowManyBytes {
    char a;
    int b;
};

struct ColorVector {
    double r;
    double g;
    double b;
    double a;
};

struct alignas(32) ColorVector2{
    double r;
    double g;
    double b;
    double a;
};


void testp8_1() {
    cout << __func__ << "() called.\n";

    cout << "sizeof(char) : " << sizeof(char) << endl;
    cout << "sizeof(int) : " << sizeof(int) << endl;
    cout << "sizeof(HowManyBytes) : " << sizeof(HowManyBytes) << endl;

    cout << endl;

    cout << "offset of char a :" << offsetof(HowManyBytes, a) << endl;
    cout << "offset of int b : " << offsetof(HowManyBytes, b) << endl;
    cout << "alignof(HowManyBytes) : " << alignof(HowManyBytes) << endl;
    cout << "alignof(int) :" << alignof(int) << endl;
    cout << "alignof(char) : " << alignof(char)  << endl;

    cout << endl;

    cout << "alignof(ColorVector) : " << alignof(ColorVector) << endl;
    cout << "sizeof(ColorVector) : " << sizeof(ColorVector) << endl;
    cout << endl;

    cout << "alignof(ColorVector2) : " << alignof(ColorVector2) << endl;
    cout << "sizeof(ColorVector2) : " << sizeof(ColorVector2) << endl;
    cout << endl;

    size_t const size = 100;
    ColorVector * const vec = new ColorVector[size];
    void * p = vec;
    size_t sz = size;
    void * aligned = align(alignof(double) * 4, size, p , sz);
    if(aligned != nullptr) {
        cout << alignof(p) << endl;
    }

    cout << __func__ << "() called. done. \n";
}