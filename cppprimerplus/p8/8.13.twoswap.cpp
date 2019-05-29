#include <iostream>
using namespace std;

template <typename T> void swap(T * a, T * b);

template <typename T> void swap(T * a, T * b, int n);

void show(int * a);

const int LIM = 8;

struct job{
    char name[40];
    double salary;
    int floor;
};

/**
 * 对于模板函数，有可能无法处理某些类型 explicit specialization
 * 为特定类型的函数提供类型具体化的模板函数
 * 
 * 对于模板函数，给定的函数名，可以有非模板函数，模板函数和显式具体化模板函数以及他们的重载版本
 * 显式类型具体化的原型和定义以template<>开头，并通过名称来指出类型
 * 类型具体化函数优先于常规模板函数，而非模板函数优先于类型具体化函数和常规模板。
 */ 
//对于模板处理， 类型具体化， 会优先使用类型具体化的函数，而不是函数模板生产的函数
template <> void swap<job>(job * j1, job * j2);
// swap<job> 这里的<job>是可选的，因为函数的参数类型已经表明了，可以简写成
// template <> void swap(job * j1, job * j2);

void show(job * j);


int main234()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    cout<<endl;

    int i = 10, j = 20;
    cout << "i = " << i << ", j = " << j << endl;
    swap(&i , &j);
    cout << "Now, i = " << i << ", j = " << j << endl;

    int d1[LIM] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[LIM] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays:" << endl;
    show(d1);
    show(d2);
    swap(d1, d2, LIM);
    cout << "swapped arrays:" << endl;
    cout << "d1 array : " << endl;
    show(d1);
    cout << "d2 array : " << endl;
    show(d2);

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping : \n";
    cout << "\nsue info : ";
    show(&sue);
    cout << "\nsidney info : ";
    show(&sidney);

    swap(&sue, &sidney);
    cout << "\nAfter job swapping: \n";
    cout << "\nsue info : ";
    show(&sue);
    cout << "\nsidney info : ";
    show(&sidney);
    
    cout<<endl;
    return 0;
}

template <typename T> void swap(T * a, T * b) {
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T> void swap(T * a, T * b, int n) {
    T temp;
    for(int i=0; i<n; i++) {
        // temp = a[i];
        // a[i] = b[i];
        // b[i] = temp;
        temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }
}

void show(int * a) {
    cout << *a << *(a + 1) << "/";
    cout << *(a+ 2) << *(a + 3) << "/";
    for(int i=4; i<LIM; i++) {
        cout << *(a + i);
    }
    cout << endl;
}

template <> void swap(job * j1, job * j2) {
    double t1;
    int t2;
    t1 = j1->salary;
    j1->salary = j2->salary;
    j2->salary = t1;

    t2 = j1->floor;
    j1->floor = j2->floor;
    j2->floor = t2;
}

void show(job * j) {
    cout << j->name << ", $" << j->salary << " on floor " << j->floor << endl;
}