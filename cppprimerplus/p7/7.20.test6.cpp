#include <iostream>

using namespace std;

int Fill_array(double * arr, int size);

void Show_array(double * arr, int size);

void Reverse_array(double * arr, int size);

int main88()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double arr[10];
    int size = Fill_array(arr, 10);
    Show_array(arr, size);
    Reverse_array(arr, size);
    cout << "Reverse array element and then array info : " << endl;
    Show_array(arr, size);
    
    cout<<endl;
    return 0;
}

int Fill_array(double * arr, int size) {
    cout << "Enter " << size << " number into the arr :" << endl;
    bool flag = true;
    int result = 0;
    double tmp;
    for(int i=0; i<size && flag; i++) {
        while(!(cin >> tmp)) {
            cin.clear();
            while(cin.get() != '\n')continue;
            flag = false;
            break;
        }
        if(flag) {
            *(arr + i) = tmp;
            result++;
        }
    }
    return result;
}

void Show_array(double * arr, int size) {
    cout << "arr value [ ";
    for(int i=0; i<size;i++) {
        cout << *(arr+i) << " ";
    }
    cout << "]" << endl;
}

void Reverse_array(double * arr, int size) {
    double tmp;
    for(int i=0; i<size/2; i++) {
        tmp = *(arr+i);
        *(arr+i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = tmp;
    }
}