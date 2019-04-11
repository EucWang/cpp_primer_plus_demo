#include <iostream>

const double * f1(const double ar[], int n);

const double * f2(const double [], int);

const double * f3(const double *, int);

/**
 * 深入学习函数指针
 * 
 * 函数指针数组
 * 
 * 二级函数指针，
 * 
 * 函数指针调用函数
 * 二级函数指针调用函数
 * 
 * 使用typedef 进行简化
 * 通过typedef能够创建类型别名
 * typedef double real;  //makes real anothe name for double
 * 这里可以开程序开始就定义 函数指针的别名
 * 
 * typedef const double * (*p_fun)(const double *, int); // p_fun就是类型别名了
 * p_fun p1 = f1;
 *  
 *
 */ 

int main283()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double av[3] = {1112.3, 1542.6, 2227.9};

    const double *(*p1)(const double *, int) = f1;   //指向函数的指针
    auto p2 = f2;      //自动得到类型

    cout << "Using pointers to function:\n";
    cout << "Address Value\n";
    cout << (*p1)(av, 3) << ": "<< *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": "<< *p2(av, 3) << endl;

    const double * (*pa[3])(const double *, int) = {f1, f2, f3};   //指向函数的指针数组
    auto pb = pa;
    cout << "\nUsing an array of pointers to function:\n";
    cout << " Address Value\n";
    for(int i=0; i<3; i++) {
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;   //控制指针函数数组的指针调用函数
    }

    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address Value\n";
    for(int i=0; i<3; i++) {
        cout << pb[i](av, 3) << ": "<<*pb[i](av, 3) << endl;   
    }

    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address Value\n";
    auto pc= &pa;                                                //指针的指针， 通过二级指针调用函数
    cout << (*pc)[0](av, 3) << ": "<<*(*pc)[0](av, 3) << endl;

    const double * (*(*pd)[3])(const double *, int) = &pa;     //手动设置指向函数的二级指针的类型
    const double * pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;

    cout << (*(*pd)[2])(av, 3) << ": " << *(*(pd)[2])(av, 3) << endl;

    
    cout<<endl;
    return 0;
}

const double * f1(const double ar[], int n){
    return ar;
}

const double * f2(const double ar[], int){
    return ar+1;
}

const double * f3(const double * ar, int){
    return ar+2;
}