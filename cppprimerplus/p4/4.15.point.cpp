#include <iostream>

/**
 * 指针的申明，赋值，以及使用
 */ 

int main8()
{
    using namespace std;
    cout<<endl;
    
    int updates = 6;
    int * p_update;      //指针变量的申明
    p_update = &updates;   //指针变量的赋值

    cout << "Value : updates = " << updates 
        << ", *p_update = " << *p_update << endl;   //指针变量的使用

    cout << "Address : &updates = " << &updates
        << ", p_update = " << p_update << endl;    //指针

    *p_update = *p_update + 1;               //通过指针来操作变量
    cout << "Now Value : updates = " << updates << endl;

    cout<<endl;
    return 0;
}
