#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>

class Customer2{
    private:
    long arrive;
    int processtime;
    public:
    Customer2(){arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
    friend std::ostream & operator<<(std::ostream & os, Customer2 & c);
};

#endif