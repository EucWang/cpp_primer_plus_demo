#include <iostream>
#include <memory>
#include "test2.h"

using namespace std;

class MathObject{
public:
    virtual double arith() = 0;
    virtual void print() = 0;
};

class Printable : public MathObject{
public:
    double arith() = 0;
    void print(){
        cout << "Output is : " << arith() << endl;
    }
};

class Add2 : public Printable{
public:
    Add2(double a, double b) : x(a) , y(b){}
    double arith(){return x + y; }
private:
    double x;
    double y;
};

class Mul3 : public Printable {
public:
    Mul3(double a, double b, double c): x(a), y(b), z(c){}
    double arith() {return x * y * z;}
private:
    double x;
    double y;
    double z;
};


/**
 * 使用final禁止派生类重写某个方法
 */ 
struct ObjectTest{
    virtual void fun() = 0;
};

struct BaseObject : public ObjectTest {
    void fun() final;
};

//下面的类将在编译阶段就不能通过，
// struct Derived : public BaseObject{
//     void fun();
// };

int testp2_23(){

    shared_ptr<Printable> a(new Add2(1, 2));
    unique_ptr<Printable> b(new Mul3(3,4,5));
    a->print();
    b->print();

    return 0;
}