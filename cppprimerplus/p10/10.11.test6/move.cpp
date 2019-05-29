#include <iostream>
#include "move.h"

using namespace std;

Move::Move(double a, double b) {
    x = a;
    y = b;
}

void Move::show_move() const {
    cout << "\n======Move info=======" << endl;
    cout << "x = " << x  << " , y = " << y << endl;
}

Move Move::add(const Move & m) const {
    return (*(new Move(m.x + x, m.y + y)));
}

void Move::reset(double a, double b) {
    x = a;
    y = b;
}