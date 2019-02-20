#include <iostream>

using namespace std;


int input_arr(double * pt, int size);

void show_arr(double * pt, int size);

double cal_arr_mean(double * pt, int size);

const int ArSize = 10;

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double arr[ArSize];
    int newSize = input_arr(arr, ArSize);
    show_arr(arr, newSize);
    double mean = cal_arr_mean(arr, newSize);
    cout << "the arr mean value is : " << mean << endl;
    
    cout<<endl;
    return 0;
}

/**
 * 输入数组内容
 */ 
int input_arr(double * pt, int size){
    cout << "Enter " << size << "number:" << endl;
    int real_size = 0;
    bool flag = true;
    int i=0;
    double tmp;
    for(int i=0; i<size && flag; i++) {
        while(!(cin >> tmp)){
            cin.clear();
            while(cin.get() != '\n')continue;
            cout << "finish input!";
            flag = false;
            break;
        }
        if(flag) {
            *(pt+i) = tmp;
            real_size++;
        }
    }
    return real_size;
}

void show_arr(double * pt, int size){
    cout << "\nshow array values : [ ";
    for(int i=0; i<size; i++) {
        cout << *(pt+i) << " ";
    }
    cout << "]";
}

double cal_arr_mean(double * pt, int size){
    double result = 0;
    for(int i=0; i<size; i++) {
        result += *(pt+i);
    }
    return result / size;
}
