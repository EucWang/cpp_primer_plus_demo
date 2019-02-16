#include <iostream>
#include <string>
using namespace std;

char * getname(void);

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char * name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete [] name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete [] name;

    cout<<endl;
    return 0;
}

char * getname()
{
    char temp[80];  //首先常见一个大数组
    cout << "Enter last name:";
    cin >> temp;  //将输入的字符串保存到这个大数组中
    char * pn = new char[strlen(temp) + 1]; //然后创建一个长度刚刚够的字符串数组
    strcpy(pn, temp); //将输入的字符串复制到这个新的字符串数组中，然后将指针返回
    return pn;
}
