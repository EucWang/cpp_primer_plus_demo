#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "test16.h"

using namespace std;

template<class T>
int reduce(T ar[], int n);
void test1();
void test2();

int test5in16(){

    test1();
    test2();
    return 0;
}

void test1(){
    long arr[10] = {1,3, 5, 7, 9, 7, 3, 5, 7, 7};
    int newSize = reduce(arr, 10);
    cout << "\n========result===========\n";
    cout << "new size of long array is " << newSize << endl;
    cout << "========result done========\n";
}

void test2(){
    string arr[12]  = {
        "hello" , "you", "can",
        "something", "right", "jellyfish",
        "you", "hello", "right",
        "jellyfish", "bigfish", "smallfish"
    };
    int size =  reduce(arr, 12);
    cout << "\n========result===========\n";
    cout << "new size of string array is " << size << endl;
    cout << "========result done========\n";
}

template<class T>
int reduce(T ar[], int n){
    cout << "size of ar is " << n << endl;
    vector<T> vec(&ar[0], &ar[n]);
    cout << "before sort:\n";
    copy(vec.begin(), vec.end(), ostream_iterator<T, char>(cout, " "));
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << "before erase:\n";
    copy(vec.begin(), vec.end(), ostream_iterator<T, char>(cout, " "));
    cout << endl;

    vec.erase(unique(vec.begin(), vec.end()) , vec.end());

    cout << "after erase:\n";
    copy(vec.begin(), vec.end(), ostream_iterator<T, char>(cout, " "));
    cout << endl;

    return vec.size();
}

