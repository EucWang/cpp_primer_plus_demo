#include <iostream>
#include <vector>
#include <iterator>

#include "test16.h"
using namespace std;

int reduce(long ar[], int n);

int test4in16(){

    long arr[10] = {1,3, 5, 7, 9, 7, 3, 5, 7, 7};
    int newSize = reduce(arr, 10);
    cout << "new size is " << newSize;
    return 0;
}

int reduce(long ar[], int n) {
    vector<long> vec(&ar[0], &ar[n-1]);
    cout << "before sort : \n";
    copy(vec.begin(), vec.end(), ostream_iterator<long,char>(cout, " "));
    cout << endl;
    sort(vec.begin(), vec.end());
    cout << "after sort and before unique: \n";
    copy(vec.begin(), vec.end(), ostream_iterator<long,char>(cout, " "));
    cout << endl;
    vector<long>::iterator end_unique = unique(vec.begin(), vec.end());
    cout << "after unique and before erase: \n";
    copy(vec.begin(), vec.end(), ostream_iterator<long,char>(cout, " "));
    cout << endl;
    vec.erase(end_unique, vec.end());
    cout << "after erase: \n";
    copy(vec.begin(), vec.end(), ostream_iterator<long,char>(cout, " "));
    cout << endl;
    return vec.size();
}