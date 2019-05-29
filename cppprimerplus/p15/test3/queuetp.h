#ifndef QUEUE_TP_H_
#define QUEUE_TP_H_

template <class Item>
class QueueTP{
    private:
        enum {Q_SIZE=10};

        //嵌套类， 位于私有部分
        class Node{
            public:
                Item item;
                Node * next;
                Node(const Item & i):item(i), next(0){}
        };

        Node * front;
        Node * rear;
        int items;
        const int qsize;

        //内置赋值函数 和 赋值运算符， 防止出错
        QueueTP(const QueueTP & q):qsize(0){}
        QueueTP & operator=(const QueueTP & q){return *this;}

    public:
        QueueTP(int qs=Q_SIZE);
        ~QueueTP();

        bool isempty() const {return items==0;}
        bool isfull() const {return items==qsize;}
        int count() const {return items;}

        bool enqueue(const Item & item);
        bool dequeue(Item & item);
};

/**
 * 构造函数
 */ 
template <class Item>
QueueTP<Item>::QueueTP(int qs):qsize(qs){
    front = rear = nullptr;
    items = 0;
}

/**
 * 析构函数
 */ 
template <class Item>
QueueTP<Item>::~QueueTP() {
    Node * temp;
    while(front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
} 

/**
 * 加入队列
 */ 
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item){
    if(isfull()){
        return false;
    }
    Node * newNode = new Node(item);
    items++;
    if(front == nullptr) {
        front = newNode;
    }else {
        rear->next = newNode;
    }
    rear = newNode;
    return true;
}

/**
 * 从队列移除
 */ 
template <class Item>
bool QueueTP<Item>::dequeue(/*out*/Item & item){
    if(front == nullptr) {
        return false;
    }
    item = front->item; //为返回值赋值
    items--;

    Node *temp = front;
    front = front->next;
    delete temp;
    if(items == 0){
        rear = nullptr;
    }
    return true;
}


#endif