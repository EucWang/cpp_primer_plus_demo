/**
 * 16.15 
 * using a functor
 * 
 */ 


#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>

#include "functor.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;
using std::ostream_iterator;
using std::sqrt;
using std::transform;
using std::plus;

/**
 * 函数对象模板,
 * 
 * transform（） 内置的预定义函数符
 */ 
template<class T>
class TooBig{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator()(const T & v) {return v > cutoff;}
};

void outint2(int n){cout << n << " ";}

double add(double a, double b) {
    return a+b;
}

int main_functor(){
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals+10);
    list<int> etcetera(vals, vals+10);

    cout << "Original lists: \n";
    for_each(yadayada.begin(), yadayada.end(), outint2);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint2);
    cout << endl;

    TooBig<int> f100(100);
    yadayada.remove_if(f100);
    etcetera.remove_if(TooBig<int>(200));

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint2);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint2);
    cout << endl;

    cout << "Predefined Functor" << endl;

    const int LIM = 5;
    double arr1[LIM] = {36, 39, 42, 45, 48};
    vector<double> gr8(arr1, arr1+LIM);
    
    ostream_iterator<double , char> out(cout, " ");

    cout << "\ngr8" << endl;
    copy(gr8.begin(), gr8.end(), out);
    cout << endl;

    // transform(gr8.begin(), gr8.end(), out, sqrt);
    /**
     * 第一个，第二个参数2个迭代器，表示集合的范围
     * 第三个参数，迭代器，表示结果输出的 迭代器
     * 第4个参数，表示作用与集合范围内所有数据的一个函数方法
     */ 
    transform(gr8.begin(), gr8.end(), out, [](double it){
        return sqrt(it);
    });

    cout << "\nOther type to use transform()\n";
    /**
     * 使用transform()操作2个迭代器，将2个集合的内容相加，然后输出到控制台
     */ 
    // transform(gr8.begin(), gr8.end(), yadayada.begin(), out, add);
    //使用内置的plus函数,位于functional头文件中
    //其他还有
    /**
     * minus, multiplies, divides, modulus, negate, equal_to, not_equal_to, greate, less, greater_equal, less_equal, logical_and, logical_or, logical_not
     *   -        *         /          %       -         ==         !=         >      <      >=             <=          &&           ||           !
     */ 
    transform(gr8.begin(), gr8.end(), yadayada.begin(), out, plus<double>());
    cout << endl;
    return 0;
}