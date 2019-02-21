#include <iostream>
using namespace std;

template <typename T> void showArray(T arr[], int n);

template <typename T> void showArray(T * arr[], int n);

template <typename T> T sumArray(T arr[], int n);

template <typename T> T sumArray(T * arr[], int n);

struct debts{
    char name[50];
    double amount;
};

int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 24000.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];  //这是指针数组

    for(int i=0; i<3; i++) {
        pd[i] = &mr_E[i].amount;
    }
    cout << "Listing Mr.E's counts of things:\n";
    showArray(things, 6);
    int total = sumArray(things, 6);
    cout << "SumArray total = " << total << endl;

    cout << "Listing Mr.E's debts:\n";
    showArray(pd, 3);
    total = sumArray(pd, 3);
    cout << total << endl;

    cout<<endl;
    return 0;
}

template <typename T> void showArray(T arr[], int n){
    cout << "template A" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T> void showArray(T * arr[], int n) {
    cout << "template B" << endl;
    for(int i=0; i<n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}

template <typename T> T sumArray(T arr[], int n){
    T total = arr[0];
    for(int i=1; i<n; i++) {
        total += arr[i];
    }
    return total;
}

template <typename T> T sumArray(T * arr[], int n){
    cout << "SumArray B" << endl;
    T total = *arr[0];
    for(int i=1; i<n; i++) {
        total += *arr[i];
    }
    return total;
}