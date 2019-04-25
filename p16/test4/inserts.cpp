/**
 * 16.11 inserts.cpp
 * 
 * use insert_iterator,  front_insert_iterator,  back_insert_iterator
 */ 

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

#include "test_iterator.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::back_insert_iterator;
using std::insert_iterator;

void output(const  string & s) {
    cout << s << " ";
}

int main_inserts(){

    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};

    //调用 copy()将指定内容复制到容器中，并覆盖容器中的原有内容
    vector<string> words(4);
    copy(s1, s1+4, words.begin());
    for_each(words.begin(), words.end(), output);  //遍历并输出到控制台
    cout << endl;

    //调用copy()， 但是将容器使用back_insert_iterator迭代器包装下， 则可以将内容添加到容器结尾处
    copy(s2, s2+2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    //调用copy()， 但是将容器使用insert_iterator迭代器包装下，则可以将内容插入到容器给定位置处
    copy(s3, s3+2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;


    return 0;
}