#include <iostream>


/**
 * 
 * cin.get(a)  
 * 方式读取内容， 输入依然被缓冲了，
 * 但是可以正确的读取空格了
 * 
 * 在C语言中，要修改变量的值，必须将变量的地址传递给函数。
 * 但是在C++中，只要函数将参数声明成引用，那么直接传递变量也是有效的。
 * 引用是C++在C语言的基础上新增加的一种类型。
 * 
 * 通常C++中传递参数的工作方式与在C语言中相同，然而cin.get(ch)不是这样
 * 
 */ 
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);

    while(ch != '#'){
        cout << ch;
        ++count;
        cin.get(ch);
    }

    cout << endl << count << " characters read\n";
    

    cout<<endl;
    return 0;
}
