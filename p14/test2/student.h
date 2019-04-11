#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <valarray>
#include <string>

using std::string;
using std::valarray;
using std::ostream;
using std::istream;

/**
 * 私有继承  
 *  ： 实现has-a关系， 基类的公有部分和保护成员都将成为派生类的私有成员
 *  ： 继承时，private是默认值，省略访问限定符将导致私有继承
 * 
 * 多重继承
 */ 
class Student2: private string, private valarray<double> {
    private:
        typedef valarray<double> ArrayDb;
        ostream & arr_out(ostream & os) const;
    public:
        Student2() : string("Null Student2"), ArrayDb() {}
        explicit Student2(const string & s) : string(s), ArrayDb() {}
        explicit Student2(int n) : string("Nully"), ArrayDb(n) {}

        Student2(const string & s, int n) : string(s), ArrayDb(n) {}
        Student2(const string & s, const ArrayDb & a): string(s), ArrayDb(a){}
        Student2(const string & s, const double * pd, int n) : string(s), ArrayDb(pd, n) {}

        ~Student2(){}

        double average() const;
        const string & name() const;

        double & operator[](int i);
        double operator[](int i) const;

        friend istream & operator>>(istream & is, Student2 & stu);
        friend istream & getline(istream & is, Student2 & stu);

        friend ostream & operator<<(ostream & os, const Student2 & stu);
};

#endif