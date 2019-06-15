#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "test4.h"

using namespace std;

double foo(){
    return M_PI;
}

/**
 * 在不使用 using namespace std; 时，
 * 这里的iterator 类型会比如下的更长，
 * 而如果使用auto，就能简化很多，并且代码可读性也 要高很多
 */ 
void loopover(vector<string> & vs) {
    // vector<string>::iterator i  =vs.begin();
    // for(; i < vs.end(); i++) {
    //     //some codes
    // }
    cout << "[";
    for(auto i = vs.begin(); i < vs.end(); i++){
        cout << *i << "\t";
    }
    cout << "]" << endl;
}

/**
 * auto不仅能简化类型声明，而且可以避免一些声明错误。
 * 
 * 即使这里 的operator*方法修改了返回值，
 * 在代码中auto也能 “自适应”
 */ 
class PI {
public:
    const float val = 3.1415927f;
    double operator*(float v) {
        return (double) val * v;  //这里扩展成double类型了
    }
};

/**
 * auto并不能解决所有精度的问题，
 * 比如数据类型的值溢出
 */ 
void test_overflow_int(){
    unsigned int a  = 4294967295;  //最大的unsigned int的值
    unsigned int b = 1;
    auto c = a + b;
    cout << "a =  " << a << endl;
    cout << "b =  " << b << endl;
    cout << "a + b = " << c << endl;
}


/**
 * 在32位编译环境下，strlen返回的是4字节的整型
 * 在64位编译环境下，strlen返回的是8字节的整型
 * 系统库<cstring> 提供了 size_t 用于支持这个类型的跨平台
 * 但是使用auto依然可以做到类型的跨平台
 * size_t 局限于 <cstring>，而auto使用更广泛
 */ 
void test_replace_size_t(){
    auto len = strlen("hello world!");
    cout << "strlen() len is " << len << endl;
}

/**
 * 再模板中使用auto， 更能提现其“自适应”
 */ 
template<typename T1, typename T2>
double sum(T1 & t1, T2 & t2) {
    auto s = t1 + t2;
    return s;
}

/**
 * max1 采用传统的 三元运算符，a和b如果分别是两个表达式，那么在这里会被运算2次
 * max2 先将a和b算出来，再用三元运算符进行比较， 就不会有这个问题
 */ 
#define max1(a, b) ((a)>(b)) ? (a) : (b)
#define max2(a, b) ({ \
    auto _a = (a); \
    auto _b = (b); \
    (_a > _b) ? _a : _b; })

int & bar(){
}

/**
 * auto 结合指针和引用一起使用
 * 对于a,c,d而言，其为auto 还是 auto * 并没有区别
 * ⚠️如果auto声明的变量是另一个变量的引用，则必须使用auto&， 比如 b 和 h
 * ⚠️指针不能指向一个临时变量
 * ⚠️nonconst的左值引用不能和一个临时变量绑定
 */ 
void test_ptr_ref(){
    int x;
    int * y = &x;

    //对于a,c,d而言，其为auto 还是 auto * 并没有区别
    //⚠️如果auto声明的变量是另一个变量的引用，则必须使用auto&， 比如 b 和 h
    auto * a = &x;
    auto & b = x;
    auto c =y;
    auto * d = y;

    // auto * e = &foo();  //编译不通过，指针不能指向一个临时变量
    // auto & f = foo();   //编译不通过，nonconst的左值引用不能和一个临时变量绑定
    auto g = bar();
    auto & h = bar();
}


float * bar2(){}

/**
 * volatile const 代表两种变量的属性： 易失的， 常量的 ; 常常一起被成为cv限定符(cv-qualifier)
 * 
 * ⚠️声明为 auto & 的变量 可以获得 表达式右值的cv限定的 const/volatile
 * auto * 也 可以获得 表达式右值的cv限定的 const/volatile
 * 声明为 auto 的不会 获得 表达式右值的cv限定的 const/volatile
 */ 
void test_auto_with_cv(){
    const auto a = foo();  // a  : const double
    const auto & b = foo();   // b : const double &

    volatile auto * c = bar2(); // c: volatile float *
    auto d = a;                // d : double        没有获得a的const
    auto & e = a;              // e : const double &    引用可以带走 const
    auto f = c;                // f: float *         //没有获得c的volatile
    volatile auto & g = c;     // g: volatile float * &   引用也带走了 volatile
}

/**
 * 初始化列表 也可以用 auto
 * new 也可以用auto
 */
void test_initilizale(){
    cout << __func__ << "() called.\n";
    auto x = 1;
    auto x1 {1};        //初始化列表可以用auto
    auto y{1};
    auto z = new auto(1);  //可以用于new
}

/**
 * auto 不能使用的情况
 */
void test_cannt_used(){
    cout << __func__ << "() called." << endl;
    char x[3];
    auto y = x;
    // auto z[3] = x;   //auto数组，这个不行的
    // vector<auto> v = {1};  //auto作为范型，这个不可能的

    auto int i = 1;  //会发出警告，但是依然会通过编译
}

// struct str{
//     auto var = 10; //auto非静态的成员变量， 这个不行的
// }

// void fun(auto x = 1){}  //形参 不能使用auto


/**
 * auto类型推导
 */ 
void testp4_4(){
    cout << __func__ << "() call. \n";
    // double foo();

    auto x = 1;
    auto y = foo();

    struct m {
        int i;
    } str;

    auto str2 = str;
    // auto z;   //无法推导，无法通过编译
    // z = x;

    vector<string> strs = {"zhang san", "li si", "wang wu"};
    loopover(strs);

    cout << "---------------" << endl;
    float radius = 1.7e10;
    PI pi;
    auto circumference = 2 * (pi * radius);  // 这里推导circumference的类型是double
    cout << circumference << endl;

    cout << "---------------" << endl;
    test_overflow_int();

    cout << "---------------" << endl;
    test_replace_size_t();

    cout << "---------------" << endl;
    int a = 3;
    long b = 5;
    float c = 1.0f;
    float d = 2.3f;
    auto e = sum<int, long>(a, b);
    auto f = sum<float ,float>(c, d);
    cout << "sum<int, long> " << e << endl;
    cout << "sum<float ,float> " << f << endl;

    cout << "---------------" << endl;
    int m1 = max1(1*2*3*4, 5+6+7+8);
    int m2 = max2(1*2*3*4, 5+6+7+8);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;

    cout << "---------------" << endl;
    test_initilizale();
    cout << "---------------" << endl;
    test_cannt_used();
    cout << __func__ << "() called done. \n";
}