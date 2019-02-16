#include <iostream>
#include <string>  // make string class available
#include <cstring> //c-style string library

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    str1 = str2;             //复制字符串对象
    strcpy(charr1, charr2);  //复制字符数组

    str1 += " paste";         // 拼接字符串对象
    strcat(charr1, " juice");   //拼接字符数组

    int len1 = str1.size();  //获取字符串长度
    int len2 = strlen(charr1);   //获取字符串数组长度， 使用cstring库

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";

    cout << "The string " << charr1 << " contains " << len2 << " characters.\n"; 


    cout<<endl;
    return 0;
}
