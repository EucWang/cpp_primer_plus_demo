#include <iostream>
using namespace std;

template <class T> T lesser(T a, T b) {
    return a < b ? a : b;
}

int lesser(int a, int b) {
    a = a <0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main246()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int m = 20;
    int n = -30;
    double x= 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;
    cout << lesser(x, y) << endl;
    cout << lesser<>(m, n) << endl;  //这里的 <>指出，编译器应选择模板函数，而不是非模板函数
    cout << lesser<int>(x, y) << endl;  //这里使用显示实例化，指定类型了。
    
    cout<<endl;
    return 0;
}
