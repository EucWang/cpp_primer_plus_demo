#include <iostream>
#include <cstring>

/**
 * 比较字符串数组相等， 不能通过 “==”来比较
 * 需要通过 函数 strcmp(a, b) 来比较
 */ 
int main15()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char word[5] = "?ate";

    for(char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }
    
    cout << "After loop ends, word is " << word << endl;

    cout<<endl;
    return 0;
}
