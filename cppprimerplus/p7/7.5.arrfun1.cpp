#include <iostream>

/**
 * 计算数组中所有元素的和
 */ 
const int ArSize = 8;

int sum_arr0(int arr[], int n);

int main67()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr0(cookies, ArSize);
    cout << "Total cookies eaten : "<< sum << endl;
    cout<<endl;
    return 0;
}

int sum_arr0(int arr[], int n) {
    int total =0;
    for(int i = 0; i < n; i++) {
        total = total + arr[i];
    }
    return total;
    
}
