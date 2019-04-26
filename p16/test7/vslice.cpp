/**
 * 16.21
 * vslice.cpp
 * 
 * using valarray slices
 */ 

#include <iostream>
#include <valarray>
#include <cstdlib>
#include "otherlib.h"

typedef std::valarray<int> vint;

void show(const vint & v, int cols);

int main_vslice(){
    const int SIZE= 12;

    using std::slice;
    using std::cout;
    vint valint(SIZE);

    int i;
    for(i =0; i<SIZE; i++) {
        valint[i] = std::rand() % 10;
    }
    cout << "Original array:\n";
    show(valint, 3);

    vint vcol(valint[slice(1, 4 ,3)]);  //取第二列
    cout << "Second column: \n";
    show(vcol, 1);

    vint vrow(valint[slice(3,3,1)]);  //取第二行
    cout << "Second row:\n";
    show(vrow, 3);

    valint[slice(2,4,3)] = 10;   //将第三列元素全部设置为10
    cout << "Set last column to 10:\n";
    show(valint, 3);

    //将第一列的元素设置为对应的第二列元素和第三列元素的和
    cout << "Set first column to sum of next two:\n";
    valint[slice(0, 4, 3)] = vint(valint[slice(1,4, 3)]) + vint(valint[slice(2,4,3)]);
    show(valint, 3);

    return 0;
}

void show(const vint & v, int cols) {
    using std::cout;
    using std::endl;

    int lim = v.size();
    for(int i=0; i<lim; i++) {
        cout.width(3);
        cout << v[i];
        if(i % cols == cols - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    } 
    if(lim % cols != 0) {
        cout << endl;
    }
}