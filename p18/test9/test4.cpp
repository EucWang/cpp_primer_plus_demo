//
// Created by 王新年 on 2019-05-25.
//

// 16.5 smart pointer  -- using three kinds of smart pointers
// requires support of C++11 shared_ptr nad unique_ptr
// requires support of c++98 auto_ptr

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#include "test9.h"

using namespace std;

//void outint3(int n) {
//    cout<< n << " ";
//}

int main_p18test4(){

    auto outint3 = [](int x){cout << x << " ";};

    list<int> one(5, 2);   // 5 个 2
    cout << "List one: ";
    for_each(one.begin(), one.end(), outint3);
    cout << endl;


    int stuff[5] = {1,2, 4,8,6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff+5);
    cout << "List two: ";
    for_each(two.begin(), two.end(), outint3);
    cout << endl;

    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three;
    three.insert(three.end(), more, more+6);
    cout << "List three: ";
    for_each(three.begin(), three.end(), outint3);
    cout << endl;

    three.remove(2);  //移除指定的元素
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outint3);

    three.splice(three.begin(), one);  //将第二个参数指定的内容移动到第一个参数指定到位置,第二个参数指定的集合清空
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint3);
    cout << endl << "List one : ";
    for_each(one.begin(), one.end(), outint3);

    three.unique();    //从list集合中删除相邻的重复的元素
    cout << endl << "list three after unique: ";
    for_each(three.begin(), three.end(), outint3);

    three.sort();  //排序
    three.unique();  //删除相邻的重复的元素
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint3);

    two.sort();   //对two进行排序
    three.merge(two); // 将two按排序的顺序合并到three中，同时清空two集合
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint3);
    cout << endl << "and then list two : ";
    for_each(two.begin(), two.end(), outint3);
    cout << endl;


    return 0;
}