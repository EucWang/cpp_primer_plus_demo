/**
 * 16.18
 * applying the STL to a string
 * listrmv.cpp
 * 
 */ 

#include <iostream>
#include <list>
#include <algorithm>
#include "strgst.h"

void show(int v){
    std::cout << v << ' ';
}

int main_listrmv(){
    using namespace std;

    const int LIM = 10;

    int ar[LIM] = {4,5,4,2,2,3,4,8,1,4};
    list<int> la(ar, ar+LIM);
    list<int> lb(la);

    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), show);
    cout << endl;

    /**
     * 这个remove()方法是链表自己的方法，删除元素之后，会自动改变链表的长度
     */ 
    la.remove(4); //删除全部的4这个元素
    cout << "After using the remove() method: \n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), show);
    cout << endl;

    list<int>::iterator last;

    /**
     * 这个remove()函数不是成员，因此不能调整链表的长度。
     * 他将没有被删除的元素放置在链表的开始位置，并返回一个指向新的
     * 超尾值的迭代器。
     * 这样，便可以用该迭代器来修改容器的长度。
     * 这里使用erase()方法来删除一个区间。
     */ 
    //last指向新的超尾值。
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), show);
    cout << endl;

    //删除新的超尾值到原来的链表结尾的元素，这样就可以正常的得到删除指定元素之后的链表长度了
    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), show);
    cout << endl;

    return 0;
}