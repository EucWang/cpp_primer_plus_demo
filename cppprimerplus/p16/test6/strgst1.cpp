/**
 * 16.17  strgst1.cpp 
 * applying the STL to a string
 * 
 */ 

#include <iostream>
#include <string>
#include <algorithm>
#include "strgst.h"

int main_strgst1(){

    using namespace std;
    string letters;

    cout << "Enter the letter grouping (quit to quit):\n";
    while(cin >> letters && letters != "quit") {
        cout << "Permutations of " << letters << endl;
        //对区间内容string排序
        cout << "use sort and then letters is :\n";
        sort(letters.begin(), letters.end());
        cout << letters << endl;

        cout << "use next_permutation() then letters is :\n";
        //next_permutation()将区间内容转换为下一种排列方式
        //对于字符串，排列按照字母递增排序进行
        while(next_permutation(letters.begin(), letters.end())) {
            cout << letters << endl;
        }
        cout << "Enter next sequence (quit to quit):";
    }

    cout << "Done!\n";
    return 0;
}