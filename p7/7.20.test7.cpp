#include <iostream>

using namespace std;

const int Max = 5;

double * Fill_array(double * ar, double * ar_end);

void Show_array(const double * ar, const double * ar_end);

void Revalue(double r, double * ar, double * ar_end);

int main()
{
    double properties[Max];

    double * p1 = properties;
    double * p2 = properties + Max;

    // int size = fill_array(properties, Max);
    double * p3 = Fill_array(p1, p2);
    Show_array(properties, p3);
    if(p3 != p1) {
        cout << "Enter revaluation factor : ";
        double factor;
        while(!(cin >> factor)) {   //输入一个数，如果输入有误，进入循环，
            cin.clear();   //清空输入队列
            while(cin.get() != '\n') {  //跳过 换行符
                continue;
            }
            cout << "Bad input; Pleas enter a number: ";  //提示用户继续输入
        }
        Revalue(factor, p1, p3);
        Show_array(p1, p3);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    
    cout<<endl;
    return 0;
}

double * Fill_array(double * ar, double * ar_end){
    using namespace std;
    double temp;
    int i = 0;
    // for(i = 0; i < limit; i++) {
    while( (ar+i) != ar_end){
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
        i++;
    }
    return ar + i;  //返回填充的数组元素的数量
}

void Show_array(const double * ar, const double * ar_end){
    int i=0;
    // for(int i = 0; i < n; i++) {
    while((ar+i) != ar_end) {
        cout << "Property #" << (i+1) << ": $";
        cout << ar[i] << endl;
        i++;
    }
}

/**
 * 修改数组的每一个元素，将每一个元素都乘以r
 */ 
void Revalue(double r, double * ar, double * ar_end){
    int i=0;
    while((ar+i) != ar_end) {
    // for(int i = 0; i < n; i++) {
        ar[i] *= r;
        i++;
    }
}