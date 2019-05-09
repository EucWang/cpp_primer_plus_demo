#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <string>
#include <memory>
#include "test16.h"

using namespace std;

// void showVector(const char * tips, vector<int> & v) ;
vector<int> lotto(int total, int randSize);

int test7in16(){

    vector<int> winners;
    winners = lotto(51, 6);
    showVector("so winner is : ", winners);

    vector<int> winners2;
    winners2 = lotto(26, 5);
    showVector("so winner2 is : ", winners2);
    return 0;
}

/**
 * 创建数列，
 * 并且打乱排序，
 * 然后截取首部指定大小
 * 然后重新排序
 * 然后使用智能指针返回给定的对象
 */ 
vector<int> lotto(int total, int randSize) {
    unique_ptr<vector<int>> a(new vector<int>());  //使用智能指针防止普通指针的异常
    // vector<int> vec = *a;
    for(int i=1; i<=total; i++) {
        a->push_back(i);
    }
    showVector("total number :", *a);
    random_shuffle(a->begin(), a->end());

    showVector("after random shuflle : " , *a);
    a->erase(a->begin()+randSize, a->end());  

    showVector("after erase part of noneed:", *a);
    sort(a->begin(), a->end()); 
    showVector("after sort:", *a);
    return *a; 
}


// void showVector(const char * tips, vector<int> & v) {
//     cout << tips << endl;
//     copy(v.begin(), v.end(), ostream_iterator<int , char>(cout, " "));
//     cout << endl;
// }