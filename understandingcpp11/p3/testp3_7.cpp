#include <iostream>
#include "test3.h"

using namespace std;


template <typename T>
class Ptr{
private:
    T * _p;
public:
    Ptr(T * p): _p(p) {}
    operator bool() const {
        if(_p != 0) {
            return true;
        }else {
            return false;
        }
    }
};

struct Rational1{
    Rational1(int n=0, int d =1)
        : num(n), den(d) {
            cout << __func__ << "(" << num << "/" << den << ")" << endl;
        }
    int num;
    int den; 
};

struct Rational2{
    explicit Rational2(int n=0, int d = 1)
        : num(n), den(d) {
            cout << __func__ << "(" << num  << "/" << den << ")" << endl;
        }
    int num;
    int den;
};

void display1(Rational1 ra) {
    cout << "Numerator : " << ra.num << " Denominator: " << ra.den << endl;
}

void display2(Rational2 ra) {
    cout << "Numerator : " << ra.num << " Denominator: " << ra.den << endl;
}

class ConvertTo{};

class Convertable{
    public:
        explicit operator ConvertTo () const {return ConvertTo();}  //使用explicit
};

void func7(ConvertTo ct){}

/**
 * C++11中， 标准将explicit 使用范围扩展到了自定义的类型换行操作符上，
 * 以支持所谓的 “显示类型转换”
 * 
 * explicit 关键字作用于 类型转换操作符上，意味着只有在直接构造目标类型或者显示类型 转换的时候可以使用该类型。
 * 
 */ 
void testp3_7(){

    cout << __func__ << "() called.\n";

    Rational1 r1_1 = 11;
    Rational1 r1_2(12);
    // Rational2 r2_1 = 21;  //无法通过编译
    Rational2 r2_2(22);
    display1(1);
    // display2(2);  //无法通过编译
    display2(Rational2(2));


    ///////////////////////////////////
    cout << "///////////////////////////////////\n" << endl;

    int a;
    Ptr<int> p(&a);
    if(p){
        cout << "valid pointer." << endl;
    } else {
        cout << "invalid pointer." << endl;
    }
    Ptr<double> pd(0);
    cout << p + pd << endl;

    ///////////////////////////////////
    cout << "///////////////////////////////////\n" << endl;
    Convertable c;
    ConvertTo ct(c);     //直接初始化， 通过,⚠️这里能通过编译，没有想明白
    // ConvertTo ct2 = c;  //隐式的使用 复制构造函数， 这里会编译失败
    ConvertTo ct3 = static_cast<ConvertTo>(c);  //  强制类型转换， 通过
    // func(c);         //隐式的调用复制构造函数， 会编译失败

    cout << __func__ << "() called done.\n";
}