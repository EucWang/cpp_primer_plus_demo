#include <iostream>


/**
 * 统计一次输入 空格有多少个，字母有多少个
 * 以“.”作为输入的结尾
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);

    while(ch  != '.')
    {
        if (ch == ' ') {
            ++spaces;
        }
        ++total;
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    cout<<endl;
    return 0;
}
