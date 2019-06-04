#include <iostream>
using namespace std;

/**
 * 任何非引用类型都可以成为联合体的数据成员， 这就是非受限联合体。
 * C++98 规定联合体中不能有非POD类型，以及有静态或者引用类型的成员的类型
 */ 

//非POD类型的结构体
struct Student{
Student(bool g, int a) : gender(g), age(a){}
bool gender;
int age;
};

union T{
    Student s;
    int id;
    char name[10];
};

/**
 * C++11中联合体 不能有静态成员变量， 但是可以有静态成员函数， 而静态成员函数唯一作用也就返回一个常数
 */ 
union T2{
static long get(){return 32;};
// static int tt2;
};

// T2::tt2 = 1;

void testp3_15(){
    cout << __func__ << "() called.\n";

    T t();

    cout << "T2::get() = " << T2::get() << endl;
    // ", T2::tt2 = " << T2::tt2 << 

    cout << __func__ << "() called.done.\n";
}