#include <iostream>

const int ArSize = 80;

/**
 * break 和continue语句
 */ 
int main208()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);
    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period : \n";
    
    for(int i = 0; line[i] != '\0'; i++) {
        cout << line[i];
        if (line[i] == '.')   //如果字符是句点。结束循环
            break;
        if (line[i] != ' ')  //只统计空格的数量，不是空格，下面语句跳过
            continue;

        spaces++;
    }
    cout << endl << spaces << " spaces\n";
    cout << "Done.\n";
    
    
    cout<<endl;
    return 0;
}
