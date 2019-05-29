#include <iostream>
using namespace std;

template <typename T> T max5(T * arr);

int main240()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    int a[] = {1,2,3,5,6};
    double b[] = {4.6, 5.7, 8.8, 9.9, 1.2};

    cout << "max int value : " << max5(a) << endl;
    cout << "max double value : " << max5(b) << endl;
    
    //cout<<endl;
    return 0;
}

template <typename T> T max5(T * arr) {
    T tmp;
    for(int i=0 ; i<5; i++) {
        if(i == 0) {
            tmp = arr[i];
        }else {
            if(arr[i] > tmp) {
                tmp = arr[i];
            }
        }
    }
    return tmp;
}