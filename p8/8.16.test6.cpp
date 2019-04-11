#include <iostream>
using namespace std;

template <typename T> T maxn(T * arr, int n);

template<> char* maxn(char * arr[], int n);

int main99()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;
    
    int a[] = {6,7,8,5,4,3};
    double b[] = {1.1, 2.2, 5.5, 3.3};
    cout << "max int value : " << maxn(a, 6) << endl;
    cout << "max double value : " << maxn(b, 6) << endl;
    
    char * c[] = {
        "When i was young",
        "I Listen to the radio",
        "Waiting for my favorite song",
        "Wahaha zhang san",
        "Apple is a apple?"
    };
    cout << "max string value : "<< maxn(c, 5) << endl;

    //cout<<endl;
    return 0;
}

template <typename T> T maxn(T * arr, int n) {
    T tmp = arr[0];
    for(int i=1 ; i<n; i++) {
        if(arr[i] > tmp) {
            tmp = arr[i];
        }
    }
    return tmp;
}

template <> char* maxn(char * arr[], int n) {
    char * tmp = *(arr+n-1);
    for(int i=n-2 ; i>=0; i--) {
        if(strlen(*(arr + i)) > strlen(tmp)) {
            tmp = *(arr + i);
        }
    }
    return (char *)(tmp);
}