#include "list.h"

#include <iostream>

// using namespace std;

// namespace mylist{
    List::List(unsigned int size) {
        mSize = size;
        current_pt = -1;
        items = new Item[mSize];
    }

    List::~List(){
        delete [] items;
    }

    void List::add(Item & item) {
        current_pt++;
        if(current_pt >=0 && current_pt < mSize) {
            items[current_pt] = item;
        }else{
            std::cerr << std::endl << "outofbound exception.." << std::endl;
        }
    }

    void List::remove(){
        if(current_pt >= 0 && current_pt < mSize) {
            current_pt--;
        }
    }

    bool List::isempty() const{
        if(current_pt < 0 ){
            return true;
        }else {
            return false;
        }
    }

    bool List::isfull() const {
        if(current_pt >= mSize - 1) {
            return true;
        }else {
            return false;
        }
    }
// }