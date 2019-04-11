#include <iostream>


double add(double x, double y);

double divide(double x, double y);

double multiply(double x, double y);

double calculate(double x, double y, double (* fx)(double, double));


int main282()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double (* pa[3])(double, double) = {add ,divide, multiply}; //指针函数数组

    cout << "Enter two number to calculate : " << endl;
    double a, b;
    while(!(cin >> a >> b)) {
        cin.clear();
        while(cin.get() != '\n')continue;
        cout << "Bad input ,try again:" << endl;
        break;
    }
    cout << "Please enter (+, -, *) to calculate the two number :";
    char ch;
    bool flag = true;
    while(flag && cin >> ch) {
        switch(ch) {
            case '+':
                cout << "result is : " << pa[0](a, b) << endl;
                flag = false;
                break;
            case '-':
                cout << "result is : " << pa[1](a, b) << endl;
                flag = false;
                break;
            case '*':
                cout << "result is : " << pa[2](a, b) << endl;
                flag = false;
                break;
            default:
                cout << "Please enter (+, -, *) to calculate the two number :";
                break;
        }
    }

    cout<<endl;
    return 0;
}

double add(double x, double y) {
    return x+y;
}

double divide(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double calculate(double x, double y, double (* fx)(double, double)) {
    return fx(x, y);
}