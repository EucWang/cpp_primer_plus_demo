#include <iostream>
#include <string>
#include "test2.h"
using namespace std;

class Mem2{
    public:
        Mem2(int i) : m(i) {}
    private:
        int m;
};

class Group2{
    public:
        Group2(){}
        Group2(int a):data(a){}
        Group2(Mem2 m ) : mem(m) {}
        Group2(int a, Mem2 m, string n) : data(a), mem(m), name(n) {}
    private:
        int data =1;   //非静态成员变量的就地初始化， 可以避免重复的在初始化列表中写上每个非静态成员
        Mem2 mem{0};
        string name{"Group"};
};

int testp2_17(){
    Mem2 mem1(1);
    Mem2 mem2(3);

    Group2 g1;
    Group2 g2(12);
    Group2 g3(mem2);
    Group2 g4(13, mem1, "zhangsan");

    return 0;
}
