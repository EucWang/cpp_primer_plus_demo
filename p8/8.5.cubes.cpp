#include <iostream>
using namespace std;

double cube(double a);
double refcube(double& ra);

int main235()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double x = 3.0;
    cout << cube(x);
    cout << " = cube of " << x << endl;

    cout << refcube(x);
    cout << " = cube of " << x << endl;
    
    cout<<endl;
    return 0;
}


double cube(double a){
    a *= a*a;
    return a;
}

/**
 * 引用修改了，那么原始数据的值也会被修改
 * 如果不想引用修改原始数据，可以定义参数为const的
 * double refcube(const double& ra);
 * 编译时会检查如果尝试通过引用修改数据会报错
 */ 
double refcube(double& ra) {
    ra *= ra * ra;
    return ra;
}
