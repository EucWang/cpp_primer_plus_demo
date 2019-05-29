/**
 * 16.13 
 * set
 * set_union()   并集
 * set_intersection()  交集
 * set_difference()    两个集合的差
 * 
 * lower_bound()  返回集合中第一个不小于键参数的成员迭代器
 * upper_bound()   返回集合中第一个大于键参数的成员的迭代器
 */ 

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

#include "test_iterator.h"

using namespace std;

int main_setops(){

    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A{s1, s1 + N};
    set<string> B{s2, s2 + N};

    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A : ";
    copy(A.begin(), A.end(), out);  //输出控制台
    cout << endl;

    cout << "Set B : ";
    copy(B.begin(), B.end(), out);  //输出控制台
    cout << endl;
    
    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);  //并集直接输出控制台
    cout << endl;
    
    set<string> C;
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    cout << "Union of A and B result set is : \n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); //交集直接输出控制台
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> D;
    cout << "Set D:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(D, D.begin()));
    copy(D.begin(), D.end(), out);
    cout << endl;

    string s3("grungy");
    D.insert(s3);
    cout << "Set D after inserction:\n";
    copy(D.begin(), D.end(), out);
    cout << endl;

    cout << "Showing  a rang:\n";
    copy(D.lower_bound("ghost"), D.upper_bound("spook"), out);
    cout << endl;

    return 0;
}