#include <iostream>
#include <string>

/**
 * 如果使用的是string对象而不是字符串数组，
 * 那么可以直接使用“==”来比较字符串是否相等， “!=” 不相等
 * 因为类函数重载了运算符
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string word = "?ate";
    for(char ch = 'a'; word != "mate"; ch++)
    {
       cout << word << endl;
       word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    
    cout<<endl;
    return 0;
}
