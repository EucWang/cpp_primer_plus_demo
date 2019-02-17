#include <iostream>

const int MAX = 5;

/**
 * 当变量时数字，但是cin输入的不是数字时，
 * 错误的输入依然被保留在输入队列中。如果向继续输入，需要采取3个步骤：
 * 1. 重置 cin 以接受新的输入
 * 2. 删除错误输入
 * 3. 提示用户再次输入
 */ 

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int golf[MAX];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << MAX << " rounds.\n";
    int i;

    for(i = 0; i < MAX; i++)
    {
        cout << "rouder #" << (i + 1) << ": ";
        while(!(cin>>golf[i])){  //输入错误的内容时，需要处理的内容
            cin.clear();             //清空并重置输入队列
            while (cin.get() != '\n')    //跳过错误的输入
            {
                continue;
            }
            cout << "Please enter a number: ";  //输出提示信息
        }
    }

    double total = 0.0;
    for(i = 0; i < MAX; i++)
    {
       total += golf[i];
    }

    cout << (total / MAX) << " = average score " << MAX << " rounds\n";
    
    
    
    cout<<endl;
    return 0;
}
