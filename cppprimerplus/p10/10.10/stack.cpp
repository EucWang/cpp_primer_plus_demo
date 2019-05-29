#include "stack.h"

Stack10::Stack10(){
    top = 0;
}

bool Stack10::is_empty() const {
    return top == 0;
}

bool Stack10::is_full() const {
    return top == MAX;
}

bool Stack10::push(/*in*/const Item & item) {
    if(top < MAX) {
        items[top++] = item;
        return true;
    }else{
        return false;
    }
}

bool Stack10::pop(/*out*/Item & item){
    if(top > 0) {
        item = items[--top];
        return true;
    }else{
        return false;
    }
}