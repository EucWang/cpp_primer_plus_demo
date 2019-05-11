#include <iostream>
#include <iomanip>
#include <cmath>

/**
 * 17.10 
 * iomanip.cpp  
 * using manipulators from iomanip
 * some systems require explicitly linking the math library
 * 
 * 
 * 为了简化设置，C++再头文件iomanip中提供了其他一些控制符，
 * 3个最常用的控制符是：
 * 
 * 可以接收1个参数,用于设置
 * setprecision()
 * setfill()
 * setw()  
 * 
 */ 
int main_iomanip(){

    using namespace std;

    cout << fixed << right;  //右对齐，显示末尾0
    cout << setw(6) << "N" 
        << setw(14) << "square root" 
        << setw(15) << "fourth root\n";
    
    double root;
    for(int n=10; n<=100; n+=10) {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n 
             << setw(12) << setfill(' ') << setprecision(3) << root 
             << setw(14) << setprecision(4) << sqrt(root)
             << endl;

    }

    



    return 0;
}