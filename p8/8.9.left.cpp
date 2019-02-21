#include <iostream>
using namespace std;

/**
 * 函数默认值
 */ 

const int ArSize = 80;

char * left(const char * str, int n = 1);

int main(){
    //cout.setf(ios_base::fixed, ios_base::floatfield);

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char* ps = left(sample, 4);
    cout << ps << endl;
    delete [] ps;

    ps = left(sample);
    cout << ps << endl;
    delete [] ps;
    return 0;
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