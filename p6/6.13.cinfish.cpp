#include <iostream>

const int MAX = 5;

/**
 * 读取数字的循环
 * 如果变量为数字类型,
 * cin >> n
 * 但是用户输入了一个单词，这种输入错误时，将产生4中情况：
 * 1. n的值保持不变
 * 2. 不匹配的输入将被保留在输入队列中
 * 3. cin对戏那个中的一个错误标记被设置
 * 4. 对cin方法的调用将返回false
 * 
 * 如果数组被填满或者输入来非数字输入， 循环将结束。
 */ 
int main98()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double fish[MAX];

    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << MAX << " fish  <q to terminate>.\n";

    cout << "fish #1: ";
    int i=0;
    while (i < MAX && cin >>fish[i])
    {
        if (++ i < MAX) {
            cout << "fish #" << (i+1) << ": ";
        }
    }

    double total = 0.0;
    for(int j = 0; j < i; j++)
    {
        total += fish[j];
    }

    if (i == 0){
        cout << "No fish.\n";
    }else {
        cout << (total / i ) << " = average weight of " 
            << i << " fish\n";
    }

    cout << "Done.\n";
    cout<<endl;
    return 0;
}
