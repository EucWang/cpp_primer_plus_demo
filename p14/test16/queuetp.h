//
// Created by 王新年 on 2019-04-11.
//

#ifndef CPP_PRIMER_PLUS_DEMO_QUEUETP_H
#define CPP_PRIMER_PLUS_DEMO_QUEUETP_H

#include <iostream>

template <typename Type>
class Queuetp {
private:
    enum{MAX=10};

    class Item{
    public:
        Type item;
        Item * next;
    };

    int size;
    Item * first;
    Item * last;
public:
    Queuetp();
    ~Queuetp();
    bool isempty();
    bool isfull();
    bool push(const Type & item);
    bool pop(Type & item);
};

template <typename Type>
Queuetp<Type>::Queuetp() {
    first = last = NULL;
    size = 0;
}

template <typename Type>
Queuetp<Type>::~Queuetp() {
    if (!isempty()) {
        Item * tmp1 = first;
        Item * tmp2;
        while(tmp1 != NULL) {
            tmp2 = first->next;
            delete tmp1;
            tmp1 = tmp2;
            std::cout << "delete one element.\n";
        }
    }
}



template <typename Type>
bool Queuetp<Type>::isempty() {
    return size==0;
}

template <typename Type>
bool Queuetp<Type>::isfull() {
    return size==MAX;
}

/**
 * 将内容放入队列, 只需要处理放置在队尾就行
 * @tparam Type
 * @param item
 * @return
 */
template <typename Type>
bool Queuetp<Type>::push(const Type &item) {
    if(isfull()){
        std::cout << "push fail, because QueueTp is full.\n";
        return false;
    }

    Queuetp<Type>::Item * tmp = new Queuetp<Type>::Item();
    tmp->item = item;
    tmp->next = NULL;

    if (isempty()){
        first = last =  tmp;
    } else {
        last->next = tmp;  //最后一个元素指向下一个元素
        last = tmp;       //移动最后一个元素到新的最后一个元素处
    }
    size++;
    return true;
}

/**
 * 从队列首部取出数据
 * @tparam Type
 * @param item
 * @return
 */
template <typename Type>
bool Queuetp<Type>::pop(Type & item) {
    if(isempty()) {
        std::cout <<"pop fail, because QueueTp is empty.\n";
        return false;
    }

    item = first->item;
    Item * tmpFirst = first->next;
    delete first;
    first = tmpFirst;
    size--;

    return true;
}

#endif //CPP_PRIMER_PLUS_DEMO_QUEUETP_H
