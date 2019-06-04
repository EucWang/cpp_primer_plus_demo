#include <iostream>
#include "test3.h"

using namespace std;

/**
 * 通过模板类is_standard_layout来判断类型是否是一个标准布局的类型
 * template <class T>
 * struct std::is_standard_layout
 * 这个模板的成员value，可以表示范型T的类型是否是标准布局的类型
 */ 

/**
 * POD包含的另外一个概念是标准布局。
 * 有如下定义：
 * 1. 所有非静态成员有相同的访问权限
 * 2. 再类或者结构体继承时， 满足条件： 非静态成员 不能同时出现在派生类和基类中
 * 3. 类中的第一个非静态成员的类型与其基类不同
 * 4. 没有虚函数和虚基类
 * 5.所有非静态成员均符合标准布局的类型，其基类也需要符合标准布局。
 */ 

/**
 * 在C++标准中，如果基类没有成员，
 * 标准允许派生类第一个成员与基类共享地址。 这样的地址共享，表明基类没有占据任何实际空间
 * 
 * 但是如果派生类的第一个非静态成员是基类类型，哪怕基类没有任何成员， 编译器依然会为基类分配1字节的空间。
 * 这是由于C++标准要求类型相同的对象必须地址不同
 * 
 * 所以在标准布局的解释中，
 * C++11 标准强制要求 派生类第一个非静态成员的类型不能是基类类型
 */ 

struct B1 {};
struct B2 {};
struct D1 : B1 {
    B1 b;    //与基类类型相同
    int i;   
};
struct D2 : B1 {
    B2 b; //与基类类型不相同
    int i;
};

void testp3_12(){
    cout << __func__ << "() called.\n";

    D1 d1;
    D2 d2;

    cout << hex;

    //打印地址
    cout << "&d1 : \t\t" << reinterpret_cast<long long>(&d1) << endl;
    cout << "&(d1.b) :  \t" << reinterpret_cast<long long>(&(d1.b)) << endl;
    cout << "&(d1.i) :  \t" << reinterpret_cast<long long>(&(d1.i)) << endl;

    cout << endl;
    cout << "&d2 : \t\t" << reinterpret_cast<long long>(&d2) << endl;
    cout << "&(d2.b) :  \t" << reinterpret_cast<long long>(&(d2.b)) << endl;
    cout << "&(d2.i) :  \t" << reinterpret_cast<long long>(&(d2.i)) << endl;


    cout << endl;
    cout << endl;
    cout << "&d1 : \t\t" << &d1 << endl;
    cout << "&(d1.b) :  \t" << &(d1.b) << endl;
    cout << "&(d1.i) :  \t" <<  &(d1.i) << endl;

    cout << endl;
    cout << "&d2 : \t\t" <<  &d2 << endl;
    cout << "&(d2.b) :  \t" <<  &(d2.b) << endl;
    cout << "&(d2.i) :  \t" << &(d2.i) << endl;

    cout << __func__ << "() called.done.\n";
}