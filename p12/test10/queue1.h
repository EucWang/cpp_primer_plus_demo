#ifndef QUEUE_1_H_

#define QUEUE_1_H_

#include "customer.h"

typedef Customer1210 Item;

class Queue1210{
    enum {Q_SIZE = 10};
    struct Node{Item item; struct Node * next;};

    private:
        Node * front;
        Node * rear;
        int items;
        const int qsize;

        //没有解决好复制构造函数以及赋值运算符，那么
        //先将这两个作为私有函数处理，防止出现错误
        Queue1210(const Queue1210 & q): qsize(0) {}
        Queue1210 & operator=(const Queue1210 & q){return * this;}
    
    public:
        Queue1210(int qs=Q_SIZE);
        ~Queue1210();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item);
        bool dequeue(Item &item);
};

#endif