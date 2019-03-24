#include <iostream>
#include "stack0.h"

Stack::Stack(int n) {
    size = n;
    top = -1;
    if(n <= 0) {
        pitems = NULL;
    }else {
        pitems = new Item[n];
    }
}

Stack::Stack(const Stack & st) {
    pitems = new Item[st.size];
    for(int i=0; i<st.size; i++) {
        pitems[i] = st.pitems[i];
    }
    size = st.size;
    top = st.top;
}

Stack::~Stack(){
    delete [] pitems;
    size = 0;
    top = -1;
}

bool Stack::isempty() const {
    return (top == -1);
}

bool Stack::isfull() const {
    return top == size - 1;
}

bool Stack::push(const Item & item) {
    if(isfull()) {
        return false;
    }
    pitems[++top] = item;
    return true;
}

bool Stack::pop(Item & item) {
    if(isempty()) {
        return false;
    }

    item = pitems[top--];
    return true;    
}

Stack & Stack::operator=(const Stack & st) {
    if(this == &st) {
        return *this;
    }
    delete [] pitems;

    pitems = new Item[st.size];
     for(int i=0; i<st.size; i++) {
        pitems[i] = st.pitems[i];
    }
    top = st.top;
    size = st.size;
    return *this;
}

ostream & operator<<(ostream & os, Stack & s) {
    os << "Stack[" 
        << "\nsize : " << s.size << ", top index is : " << s.top
        << "\npitems : ";
    if(s.isempty()) {
        os << "none";
    }else {
        for(int i=0; i<=s.top; i++) {
            os << s.pitems[i] << " ";
        }
    }
    os << "]" << endl;
    return os;
}

