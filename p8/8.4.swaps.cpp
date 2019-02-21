#include <iostream>
using namespace std;

/**
 * 引用作为函数参数传递
 */ 
void swapr(int& a, int& b);

/**
 * 指针作为函数参数传递
 */ 
void swapp(int* p, int* q);

/**
 * 函数参数按值传递
 */ 
void swapv(int a, int b);


int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1
         << "wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1
         << "wallet2 = $" << wallet2 << endl;


    cout << "Using pointers to swap contents:\n";
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = $" << wallet1
         << "wallet2 = $" << wallet2 << endl;


    cout << "Tryping to use passing by value:\n";
    swapv(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1
         << "wallet2 = $" << wallet2 << endl;




    cout<<endl;
    return 0;
}


/**
 * 引用作为函数参数传递
 */ 
void swapr(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


/**
 * 指针作为函数参数传递
 */ 
void swapp(int* p, int* q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}


/**
 * 函数参数按值传递, 不能修改原来的数据
 */ 
void swapv(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
