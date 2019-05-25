
#include <iostream>
#include <string>
#include <initializer_list>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

template<typename T>
T average_list(const std::initializer_list<T> & t) {
    T total;
//    decltype(t.begin()) total;
//    for_each(t.begin(), t.end(),[&](T * x){total+=*x;});
    for(auto p = t.begin(); p != t.end(); p++){
        total += *p;
    }
    return total / t.size();
}

/**
 * 练习使用 initializer_list模板类 接收初始化列表参数
 *
 * @return
 */
int main_p18test1(){

    using namespace std;

    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;


    return 0;
}