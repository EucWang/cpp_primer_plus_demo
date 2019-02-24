#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

/**
 * 类实现抽象数据类型
 * ADT
 * 用数组模拟栈结构
 */ 
class Stack {
    private:
      enum
      {
          MAX = 10
      };
      Item items[MAX];
      int top;
      
    public:
      Stack();
      bool is_empty() const;
      bool is_full() const;
      bool push(const Item & item);
      bool pop(Item &item);
};

#endif