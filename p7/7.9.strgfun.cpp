#include <iostream>

unsigned int c_in_str(const char * str, char ch);

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char mmm[15] = "minimum";

    const char * wail = "ululate";

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    
    cout<<endl;
    return 0;
}

/**
 * 统计 字符ch 在str字符串中出现的次数
 */ 
unsigned int c_in_str(const char * str, char ch) {
    unsigned int count = 0;
    while(*str) {    // 只要 *str 不是空值字符 \0， *str就不是非零值
        if(*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}