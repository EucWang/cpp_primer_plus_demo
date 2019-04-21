//constcast.cpp -- using const_cast<>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void change(const int * pt, int n);

/**
 * const_cast 运算符可以删除const int * pt 中的const，
 * 使得编译器能够接受 change()中的语句：
 * 但是由于pop2声明时就是const的，因此编译器会禁止修改它，
 */ 
int main_constcast(){

    int pop1 = 38383;
    const int pop2 = 2000;

    cout << "pop1, pop2 : " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);

    cout << "pop1, pop2 : " << pop1 << ", " << pop2 << endl;
    return 0;
}

void change(const int * pt, int n) {
    int * pc;

    pc = const_cast<int *>(pt);
    *pc += n;
}