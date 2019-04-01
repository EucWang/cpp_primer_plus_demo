#ifndef STACK_TP_H_
#define STACK_TP_H_

#include <iostream>
using std::cout;
using std::endl;

//两种方式都可以
// template <class Type>
template <typename Type>
class Stack {
    private:
        enum {MAX= 10};
        Type items[MAX];
        int top;
    public:
        Stack();
        ~Stack(){cout << "!Stack() .."; };
        bool isempty();
        bool isfull();
        bool push(const Type & item);
        bool pop(Type & item);
};

template<class Type>
Stack<Type>::Stack(){
    top = 0;
    cout << "Stack() constructor.." << endl;
}

template <class Type>
bool Stack<Type>::isempty(){
    cout << "isempty() top value is " << top << endl;
    return top == 0;
};

template<class Type>
bool Stack<Type>::isfull(){
    cout << "isfull() top value is " << top << endl;
    return top==MAX;
};

template<class Type>
bool Stack<Type>::push(const Type & item) {
    cout << "push() top value is " << top << endl;
    if(top < MAX) {
        items[top++]=item;
        cout << "push() success and then top is " << top << endl;
        return true;
    }else {
        cout << "push() fail." << endl;
        return false;
    }
};

/**
 * 移除
 */ 
template<class Type>
bool Stack<Type>::pop(Type & item) {
    cout << "before pop() top value is " << top << endl;
    if(top > 0) {
        item = items[--top];
        cout << "after pop() success and then top is " << top << endl;
        return true;
    } else {
        cout << "pop() fail." << endl;
        return false;
    }
};

#endif