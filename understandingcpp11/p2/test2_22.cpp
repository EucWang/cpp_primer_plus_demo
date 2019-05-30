#include <iostream>
#include "test2.h"
using namespace std;

#define UNIT_TEST

template<typename T> class DefenderT {
public:
    friend T;
    void defence(int x, int y) {cout << "defence [" << x << ", " << y << "]" << endl;}
    void tackle(int x, int y) {{cout << "tackle [" << x << ", " << y << "]" << endl;}}
private:
    int pos_x = 15;
    int pos_y = 0;
    int speed = 2;
    int stamina = 120;
};

template <typename T> class AttackerT {
public:
    friend T;
    void move(int x, int y) {cout << "move [" << x << ", " << y << "]" << endl;}
    void speedup(float ratio){cout << "speedup " << ratio << endl; }
private:
    int pos_x = 0;
    int pos_y = 0;
    int speed = 3;
    int stamina = 100;
};

// using DefenderI = DefenderT<int>;
// using AttackerI = AttackerT<int>;

#ifdef UNIT_TEST

class ValidatorT{
public:
    void validate(int x, int y, DefenderT<ValidatorT> & d){d.tackle(x, y);cout << "pos : [" << d.pos_x << ", " << d.pos_y << "]"<< endl;}
    void validate(int x, int y, AttackerT<ValidatorT> & a){a.move(x, y);}
};

using DefenderTest = DefenderT<ValidatorT>;
using AttackerTest = AttackerT<ValidatorT>;

int testp2_22(){

    DefenderTest d;
    AttackerTest a;

    a.move(15, 30);
    d.defence(15, 30);
    a.speedup(1.5f);
    d.defence(15, 30);

    ValidatorT v;
    v.validate(7, 0, d);
    v.validate(1, -10, a);

    return 0;
}

#endif
