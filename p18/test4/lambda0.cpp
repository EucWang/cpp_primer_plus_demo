//
// Created by 王新年 on 2019-05-23.
//

#include "lambda0.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const long size1 = 39L;
const long size2 = 100 * size1;
const long size3 = 100 * size2;

bool f3(int x){return x % 3 == 0;}
bool f13(int x){return x % 13 == 0;}


/**
 * 18.4 lambda0.cpp
 * using lambda expressions
 *
 * @return
 */
int mian_lanbda0() {

    vector<int> numbers(size1);

    srand(time(0));

    generate(numbers.begin(), numbers.end(), rand); //填充随机数

    cout << "Sample Size = " << size1 << "\n";
    int count3 = count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';

    int count13 =  count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13 : " << count13 << "\n\n";

    cout << "===================================\n";
    numbers.resize(size2);
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample Size = " << size2 << '\n';

    class f_mod {
    private:
        int dv;
    public:
        f_mod(int d = 1):dv(d){}
        bool operator()(int x) {return x % dv == 0;}
    };

    count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << endl;

    count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << endl;


    cout << "===================================\n";
    numbers.resize(size3);
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample Size = " << size3 << '\n';

    count3 = count_if(numbers.begin(), numbers.end(), [](int x){return x%3==0;});
    cout << "Count of numbers divisible by 3: " << count3 << endl;
    count13 = count_if(numbers.begin(), numbers.end(), [](int x){return x%13==0;});
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    return 0;

}