#ifndef USELESS_H_
#define USELESS_H_

#include <iostream>
using namespace std;

class Useless{
private:
    int n;
    char * pc;
    static int ct;
    void showObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f);  //普通的复制构造函数，执行深度复制
    Useless(Useless && f);       //移动构造函数
    ~Useless();


    Useless operator+(const Useless & f) const;
    void showData() const;


    //test3.cpp 需要用到的操作
    Useless & operator=(const Useless & f);  //复制运算符
    Useless &operator=(Useless && f);        //移动运算符， 区分点就在于 右边的值 是 "左值" 还是 "右值"
};

#endif