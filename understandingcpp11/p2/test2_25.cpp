#include <iostream>
#include "test2.h"

using namespace std;

struct Base10{
    virtual void turing() = 0;
    virtual void dijkstra() = 0;
    virtual void vneumann(int g) = 0;
    virtual void dknuth() const;
    void print();
};

struct DerivedMid : public Base10{
    void vneumann(double g);
};

/**
 * override 修饰符可以让编译器辅助的做一些检查，从而保证重载的正确性
 */ 
struct DerivedTop : public DerivedMid{
    void turing() override;
    void dijkstra() override;
    // void vneumann(double g) override;  //不能通过编译 ，参数不一致，并非重载
    // void dknuth() override;            //不能通过编译， 常量性不一致，非虚函数重载
    // void print() override;  //不能通过编译，非虚函数重载
};

int testp2_25(){

    return 0;
}