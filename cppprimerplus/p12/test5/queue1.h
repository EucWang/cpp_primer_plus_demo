#ifndef QUEUE_1_H_

#define QUEUE_1_H_

#include "customer.h"

typedef Customer Item;

class Queue{
    enum {Q_SIZE = 10};
    struct Node{Item item; struct Node * next;};

    private:
        Node * front;
        Node * rear;
        int items;
        const int qsize;

        //没有解决好复制构造函数以及赋值运算符，那么
        //先将这两个作为私有函数处理，防止出现错误
        Queue(const Queue & q): qsize(0) {}
        Queue & operator=(const Queue & q){return * this;}
    
    public:
        Queue(int qs=Q_SIZE);
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item);
        bool dequeue(Item &item);
};

#endif