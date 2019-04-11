#include <iostream>
#include "move.h"

using namespace std;

int main209()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);

    Move move1 = Move();
    move1.show_move();

    move1.reset(101.1, 99.1);
    cout << endl;
    cout << "reset move : \n";
    move1.show_move();

    Move move2 = Move(-2, 10.1);
    Move move3 = move1.add(move2);

    cout << "move3 info :" << endl;
    move3.show_move();

    // delete &move3;

    return 0;
}
