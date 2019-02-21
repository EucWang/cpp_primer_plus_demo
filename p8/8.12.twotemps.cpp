#include <iostream>
using namespace std;

template <typename T> void swap(T * a, T * b);

template <typename T> void swap(T * a, T * b, int n);

void show(int * a);

const int LIM = 8;


int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
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