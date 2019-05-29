/**
 * 16.16 
 * funadap.cpp  -- using function adapters
 * 
 * 将接受两个参数的函数符转换为接受1个参数的函数符
 * bind1st(f2, val)
 */ 

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include "functor.h"

using namespace std;

void show(double);

/**
 * 
 */ 
int main_funadap(){
    const int LIM = 6;

    double arr1[LIM] = {28, 29, 30 , 35, 38, 39};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};

    vector<double> gr8(arr1, arr1+LIM);
    vector<double> m8(arr2, arr2+LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), show);
    cout << endl;
    
    cout << "m8:\t";
    for_each(m8.begin(), m8.end(), show);
    cout << endl;

    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(),  plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), show);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), show); 
    cout << endl;

    return 0;
}

void show(double it) {
    cout.width(6);
    cout << it << " ";
}