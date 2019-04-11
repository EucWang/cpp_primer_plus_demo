#include <iostream>
using namespace std;

/**
 *  这里不能使用 引用，只能使用 指针
 */ 
template <class T>
void swap2(T & a, T & b);

template void swap2<int>(int& a, int& b);
template void swap2<double>(double& a, double& b);

int main241()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;

    int i=20;
    int j =30;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
//    swap<int &>(i,j);
    swap2<int>(i,j);
    cout << "Now i, j = "<< i << ", "<< j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-gererated double swapper:\n";
    double& xr = x;
    double& yr = y;
    swap2<double>(xr, yr);
    cout << "Now x, y = " << x << ", " << y << ".\n";
    
    // cout<<endl;
    return 0;
}

template <class T>
void swap2(T & a, T & b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
