#include <iostream>

const int Max = 5;

int fill_array(double ar[], int limit);

void show_array(const double ar[], int n);

void revalue(double r, double ar[], int n);


int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if(size > 0) {
        cout << "Enter revaluation factor : ";
        double factor;
        while(!(cin >> factor)) {   //输入一个数，如果输入有误，进入循环，
            cin.clear();   //清空输入队列
            while(cin.get() != '\n') {  //跳过 换行符
                continue;
            }
            cout << "Bad input; Pleas enter a number: ";  //提示用户继续输入
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    
    cout<<endl;
    return 0;
}


int fill_array(double ar[], int limit){
    using namespace std;
    double temp;
    int i;
    for(i = 0; i < limit; i++) {
        cout << "Enter value #" << (i+1) << ": ";
        cin >> temp;
        if(!cin) {      //输入有误
            cin.clear();  //清空输入队列
            while(cin.get() != '\n'){   //过滤掉换行
                continue;
            }
            cout << "Bad input; input process terminated.\n";  //提示
            break;    //跳出循环
        } else if( temp < 0) {   //正常输入，但是输入的是负数，跳出循环
            break;
        }
        ar[i] = temp;
    }
    return i;  //返回填充的数组元素的数量
}

void show_array(const double ar[], int n){
    using namespace std;
    for(int i = 0; i < n; i++) {
        cout << "Property #" << (i+1) << ": $";
        cout << ar[i] << endl;
    }
}

/**
 * 修改数组的每一个元素，将每一个元素都乘以r
 */ 
void revalue(double r, double ar[], int n){
    for(int i = 0; i < n; i++) {
        ar[i] *= r;
    }
}