#include <iostream>
using namespace std;

const int ArSize = 40;

void strcount(const char * str);


int main()
{
   
    char input[ArSize];
    char next;          //next缓存超过字符串长度或者是换行符

    cout << "Enter a line:\n";
    cin.get(input, ArSize);  //如果没有超过字符串长度，然后会把换行符保留在输入队列中
    while(cin) {             //让cin.get(char *, int)读取空行会导致 cin 为false
        cin.get(next);
        while(next != '\n') cin.get(next);//消费掉多余的输入

        strcount(input);

        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye!\n";

    return 0;
}

void strcount(const char* str) {
    static int total = 0;
    int count = 0;
    cout << "\"" << str << "\" contains ";
    while(*str++) {
        count++;
    } 
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
