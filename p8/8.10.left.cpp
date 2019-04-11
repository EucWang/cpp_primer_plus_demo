#include <iostream>
using namespace std;

/**
 * 函数重载
 */ 

const int ArSize = 80;

char * left(const char * str, int n = 1);
unsigned long left(unsigned long num, unsigned ct);

int main228(){
    const char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    
    for(i = 1; i<10; i++) {
        cout <<  endl << left(n, i) << endl;
        char * temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }
    return 0;
}

unsigned long left(unsigned long num, unsigned ct) {
    unsigned digits = 1;
    unsigned long n = num;

    if(ct == 0 || num == 0) {
        return 0;
    }

    while( n /= 10) {
        digits++;   // 计算数字的总位数
    }
    if(digits > ct) {
        ct = digits - ct;  //得到需要循环的次数
        while(ct --) {
            num /= 10;
        }
        return num;
    } else {   //需要截取的位数大于或者超过了数字的位数，则直接返回该数
        return num;
    }
}

char* left(const char* str, int n) {
    if(n<0){ n = 0; }

    char* p = new char[n+1];
    int i;
    for(i = 0; i<n && str[i]; i++) {  //直接判断字符串中的长度，可以比对字符是否不是'\0'，是'\0'则为false
        p[i] = str[i];
    }
    while(i <= n) {
        p[i++] = '\0';
    }
    return p;
}