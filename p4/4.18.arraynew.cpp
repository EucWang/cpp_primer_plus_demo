#include <iostream>


int main3() {
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    double * p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << endl;

    //指针算术
    p3 = p3 + 1;      //指针后移，指向第二个元素

    cout << "Now p3[0] = " << p3[0] << endl;
    cout << "p3[1] is " << p3[1] << endl;

    p3 = p3 - 1;  //指针前移， 重新指向第一个元素
    delete [] p3;   //删除数组

    cout<<endl;
    return 0;
}