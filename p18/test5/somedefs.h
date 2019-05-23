//
// Created by 王新年 on 2019-05-23.
//
// 18.6 定义了一个模板方法 和 两个函数对象

#ifndef CPP_PRIMER_PLUS_DEMO_SOMEDEFS_H
#define CPP_PRIMER_PLUS_DEMO_SOMEDEFS_H


#include <iostream>

/**
 * 每次调用时， 模板参数T都被设置为double， 模板参数F都接收一个double值并返回一个double值，貌似每次F的类型都相同。
 * 因此 这个模板方法只会实例化模板一次。
 *
 * 实际上，根据 F的不同，会实例化模板多次
 * F是函数指针时，其类型为 double(*)(double)， 所以两次调用不同的函数指针，会实例化一次
 * 当F是 函数对象时， 不同的函数对象也会引起多次实例化
 * 当F 是 lambda 表达式时， lambda表达式 不同，则也会多次实例化模板
 *
 * @tparam T
 * @tparam F
 * @param v
 * @param f
 * @return
 */
template <typename T, typename F>
T use_f(T v, F f) {
    static int count = 0;
    count ++;

    std::cout << " use_f count = " << count
        << ", &count = " << &count << std::endl;
    return f(v);
}

#include <functional>

/**
 * 18.9
 * 将模板函数的第二个参数指明为 function包装器对象，
 * 那么在调用的时候，就需要明确的指明类型，
 * 而第二个参数就可以直接接收不同的 函数指针/函数对象/lambda表达式
 *
 * @tparam T
 * @param v
 * @param f
 * @return
 */
template <typename T>
T use_f2(T v, std::function<T(T)> f) {
    static int count = 0;
    count ++;

    std::cout << " use_f count = " << count
        << ", &count = " << &count << std::endl;
    return f(v);
}

class Fp {
private:
    double z_;
public:
    Fp(double z=1.0):z_(z){}
    double operator()(double p){return z_ * p;}
};

class Fq {
private:
    double z_;
public:
    Fq(double z = 1.0): z_(z){}
    double operator()(double q) {return z_ * q;}
};

#endif //CPP_PRIMER_PLUS_DEMO_SOMEDEFS_H
