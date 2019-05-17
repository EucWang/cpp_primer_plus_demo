#include <iostream>
#include <cstdio>

/**
 * 创建临时文件的文件名
 * tmpnam() 函数创建一个临时文件名，将它放在参数指定的C-风格的字符串中
 * TMP_MAX     不重复的情况下，tmpnam()在当前目录下可调用的次数
 * L_tmpnam    临时文件名包含的字符数
 * cstdio头文件中有定义 方法  ： 
 * 
 */ 
int main_tmpname(){

    using namespace std;

    cout << "This system can generate up to " << TMP_MAX
        << " temporary names of up to " << L_tmpnam
        << " characters.\n";

    char pszName[L_tmpnam] = {'\0'};
    cout << "Here are ten names:\n";
    for(int i=0; i<10; i++) {
        tmpnam(pszName);
        cout << pszName << endl;
    }

    return 0;
}