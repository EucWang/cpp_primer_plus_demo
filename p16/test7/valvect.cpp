/**
 * 16.20
 * valvect.cpp
 * 
 * comparing vector and valarray
 */ 

#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

#include "otherlib.h"

int mian_valvect(){
    using namespace std;

    //input vector data
    vector<double> data;
    double temp;
    cout << "Enter numbers (c=0 to quit) :" << endl;
    while(cin >> temp && temp > 0) {
        data.push_back(temp);
    }

    //sort vector data
    sort(data.begin(), data.end());
    int size =data.size();

    //construct a valarray with vector's data
    valarray<double> numbers(size);
    int i;
    for(i =0; i<size; i++) {
        numbers[i] = data[i];
    }

    //operator
    valarray<double> sq_rts(size);
    sq_rts = sqrt(numbers);

    valarray<double> results(size);
    results = numbers + 2.0 * sq_rts;


    cout.setf(ios_base::fixed);
    cout.precision(4);
    cout << "\t  number\tsq_rts\tresult\n";
    for(i = 0; i<size; i++) {
        cout << i << "\t";
        cout.width(8);
        cout << numbers[i] << "; ";
        cout.width(8);
        cout << sq_rts[i] <<"; ";
        cout.width(8);
        cout << results[i] << endl;
    }

    cout << "Done!\n";
    return 0;
}