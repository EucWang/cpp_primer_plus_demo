#include <iostream>
#include <cctype>

/**
 * ctype库函数
 * 
 * isalpha()   检查字符是否是字母字符
 * isdigits()  检查字符是否是数字字符
 * isspace()    检查字符是否是恐怖，如换行符，空格，制表符
 * ispunct()   检查字符是否是标点符号
 * isalnum()   检查字符是否是字母或者数字字符
 * islower()   小写字母
 * isupper()   大些字母
 * 
 * tolower()  返回小写字母
 * toupper()   返回大写字母
 */ 

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cout << "Enter text for analysis, and type @ to terminate input.\n";
    cin.get(ch);
    while(ch != '@') {
        if (isalpha(ch)) {
            chars++;
        }else if(isspace(ch)) {
            whitespace++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (ispunct(ch)) {
            punct++;
        } else {
            others++;
        }
        cin.get(ch);
    }
    cout << chars << " letters. "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    cout<<endl;
    return 0;
}