#include "queue1.h"
#include <iostream>

using namespace std;

Queue1210::Queue1210(int qs):qsize(qs) {
    front = rear = NULL;
    items = 0;
}

bool Queue1210::enqueue(const Item & item) {
    if(isfull()) {
        return false;
    }
    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if(front == NULL) {
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue1210::isempty() const {
    return items == 0;
}

bool Queue1210::isfull() const {
    return items == qsize;
}

int Queue1210::queuecount() const {
    return items;
}

bool Queue1210::dequeue(Item & item) {
    if(front == NULL) {
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if(items == 0) {
        rear = NULL;
    }
    return true;
}

Queue1210::~Queue1210(){
    Node * temp;
    while(front != NULL) {
        temp = front;
        front = front->next;
        delete temp;
    }
}