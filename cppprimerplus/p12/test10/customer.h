#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>

class Customer1210{
    private:
    long arrive; //到达时间
    int processtime;   //需要占用atm的时间，也就是下一个顾客需要等待的时间
    public:
    Customer1210(){arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
    friend std::ostream & operator<<(std::ostream & os, Customer1210 & c);
};

#endif