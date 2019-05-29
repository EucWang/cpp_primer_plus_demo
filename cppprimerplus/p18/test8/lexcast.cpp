#include <iostream>
#include <string>

/**
 * 头文件位于 /usr/local/include/boost
库路径位于 /usr/local/lib
 */ 
// #include "boost/lexical_cast.hpp"
#include <boost/lexical_cast.hpp>

/**
 * 18.11 simple cast from float to string
 * 
 * lexical_cast()  方法将float转换成string
 * 
 */ 
int main_lexcast(){

    using namespace std;
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " to ";
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;
    return 0;
}