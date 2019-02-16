#include <iostream>

/**
 * C++的I/O工具和C不同，
 * cin对象
 * 
 * 使用原始的cin进行输入
 * 
 * 如果程序要使用循环来读取来自键盘的文本输入，则必须有办法知道何时停止读取。
 *
 * cin在读取char值时，会忽略空格和换行符。
 * 因此输入中的空格没有被回显，也没有被包括在计数内
 * 
 * 发送给cin的输入被缓冲了。
 * 只有在用户按下回车键后，他输入的内容才会被发送给程序。
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;

    while(ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;
    }

    cout << endl << count << " characters read\n";
    
    cout<<endl;
    return 0;
}
