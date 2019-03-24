#ifndef STACK_0_H_
#define STACK_0_H_

#include <iostream>
using namespace std;
typedef unsigned long Item;

class Stack {
    private:
       
        enum {MAX = 10};
        Item * pitems;
        int size;
        int top;
    public:
        Stack(int n=MAX);
        Stack(const Stack & st);  //复制构造函数
        ~Stack();

        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & item);

        Stack & operator=(const Stack & st);  //赋值运算符

        friend ostream & operator<<(ostream & os, Stack & s);
};

#endif