#include <iostream>

/**
 * 计算调和平均数
 * 调和平均数（harmonic mean）又称倒数平均数，
 * 是总体各统计变量倒数的算术平均数的倒数。调和平均数是平均数的一种
 * 计算公式： hn =  n / ((1/x1) + (1/x2) + ... + (1/xn))
 */ 
double harmonic_mean(double a, double b);

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double x, y;
    cout << "Please enter two number to calculate harmonic mean value : ";
    bool flag = true;
    while(flag) {
        while(!(cin >> x >> y)){
            cin.clear();
            while(cin.get() != '\n')continue;
            cout << "Bad input , enter again: ";
        }
        if(x == 0 || y == 0) {
            break;
        }
        cout << "harmonic mean value : " << harmonic_mean(x, y) << endl;
        cout << "Next two number :";
    }
    
    cout<<endl;
    return 0;
}

double harmonic_mean(double a, double b) {
    return 2.0 * a * b / (a + b);
}
