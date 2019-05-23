//
// Created by 王新年 on 2019-05-23.
// 18.8 using a function wrapper as an argument

#include "somedefs.h"
#include <iostream>
#include <functional>
#include "test5.h"

double dub2(double x){return 2.0 * x;}

double square2(double x){return x*x;}

using namespace std;

double y = 1.21;


void test_wrapped1();
void test_wrapped2();
void test_wrapped3();

int main_wrapped(){
//     test_wrapped1();
//     test_wrapped2();
     test_wrapped3();
    return 0;
}

/**
 * 多个包装器
 */
void test_wrapped1(){

    function<double(double)> ef1 = dub2;
    function<double(double)> ef2 = square2;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 = [](double u){return u * u;};
    function<double(double)> ef6 = [](double u){return (u + u)/2.0;};

    cout << " Function pointer dub: \n";
    cout << " " << use_f(y, ef1) << endl;
    cout << "Function pointer square : " << endl;
    cout << "  " << use_f(y, ef2) << endl;
    cout << "Function object Fp : \n";
    cout << "  " << use_f(y, ef3) << endl;
    cout << "Function object Fq : \n";
    cout << " "  << use_f(y, ef4) << endl;
    cout << "Lambda expression 1 :\n";
    cout << " " << use_f(y, ef5) << endl;
    cout << "Lambda expression 2 :\n";
    cout << " " << use_f(y, ef6) << endl;
}


/**
 * 一个包装器用于多个不同类型
 */
void test_wrapped2(){

    typedef function<double(double)> ef;
//    using ef = function<double(double)>;

    cout << " Function pointer dub: \n";
    cout << " " << use_f(y, ef(dub2)) << endl;

    cout << "Function pointer square : " << endl;
    cout << "  " << use_f(y, ef(square2)) << endl;

    cout << "Function object Fp : \n";
    cout << "  " << use_f(y, ef(Fq(10.0))) << endl;

    cout << "Function object Fq : \n";
    cout << " "  << use_f(y, ef(Fp(10.0))) << endl;

    cout << "Lambda expression 1 :\n";
    cout << " " << use_f(y, ef([](double u){return u * u;})) << endl;

    cout << "Lambda expression 2 :\n";
    cout << " " << use_f(y, ef([](double u){return (u + u)/2.0;})) << endl;

}

/**
 * 将包装器作为模板函数的入参,
 * 这里就必须明确指明模板的范型类型了
 */
void test_wrapped3() {
    cout << " Function pointer dub: \n";
    cout << " " << use_f2<double>(y, dub2) << endl;

    cout << "Function pointer square : " << endl;
    cout << "  " << use_f2<double>(y, square2) << endl;

    cout << "Function object Fp : \n";
    cout << "  " << use_f2<double>(y, Fq(10.0)) << endl;

    cout << "Function object Fq : \n";
    cout << " "  << use_f2<double>(y, Fp(10.0)) << endl;

    cout << "Lambda expression 1 :\n";
    cout << " " << use_f2<double>(y, [](double u){return u * u;}) << endl;

    cout << "Lambda expression 2 :\n";
    cout << " " << use_f2<double>(y, [](double u){return (u + u)/2.0;}) << endl;

}
