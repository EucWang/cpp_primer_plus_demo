//
// Created by 王新年 on 2019-05-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

const long size = 390000l;

using namespace std;

/**
 * 18.5
 * lambda1
 * using captured variables
 *
 * lambda 可访问作用域内的任何动态变量
 *
 *
 * @return
 */
int main_lambda1(){

    vector<int> numbers(size);

    srand(time(0));
    generate(numbers.begin(), numbers.end(), rand);

    cout << "Sample size = " << size << endl;

    int count3 = count_if(numbers.begin(), numbers.end(), [](int x){return x % 3==0;});
    cout << "Count of numbers divisible by 3 : " << count3  << endl;

    int count13 = 0;
    for_each(numbers.begin(), numbers.end(), [&count13](int x){count13 += (x%13 == 0);});
    cout << "Count of numbers divisible by 13 : " << count13 << endl;

    count3 = count13 = 0;
    for_each(numbers.begin(), numbers.end(), [&](int x){count3 +=(x%3==0);count13+=(x%13==0);});
    cout << "Count of numbers divisible by 3: " << count3 << endl;
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    return 0;
}