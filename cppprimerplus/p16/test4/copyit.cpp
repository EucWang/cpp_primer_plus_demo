/**
 * 16.10 copyit.cpp 
 * use copy() and iterators
 * use istream_iterator, ostream_iterator ， reverse_iterator
 */ 

#include  <iostream>
#include <iterator>
#include <vector>

#include "test_iterator.h"

using namespace std;

int main_copyit(){


    int casts[10] = {6,7,2, 9, 4, 11, 8, 7, 10, 5};

    vector<int> dice(10);

    copy(casts, casts+10, dice.begin());

    cout << "Let the dice be cast!\n";

    ostream_iterator<int ,char> out_iter(cout, " ");
    copy(dice.begin(), dice.end(), out_iter);  //将vector内容复制到输出流，即控制台显示
    cout << endl;

    cout << "Implict use of reverse iterator.\n";
    copy(dice.rbegin(), dice.rend(), out_iter);  //反向将vector内容复制到输出流迭代器中
    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;              //使用反响迭代器，一个一个的迭代元素
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri) {
        cout << *ri << " ";
    }
    cout << endl;

    return 0;
}