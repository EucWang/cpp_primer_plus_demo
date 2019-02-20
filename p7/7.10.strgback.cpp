#include <iostream>

char * buildstr(char c, int n);

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int times;
    char ch;
    cout << "Enter a character : ";
    cin >> ch;
    cout << "Enter an integer : " ;
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete []ps;  //用完new一定记得delete

    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;  //用完new一定记得delete
    
    cout<<endl;
    return 0;
}

/**
 * 创建一个字符串，用字符c填充， 字符串长度为n
 * 返回的字符串不需要的使用一定要记得释放内存
 * 用完new一定记得delete
 */ 
char * buildstr(char c, int n) {
    char * pstr = new char[n+1];
    pstr[n] = '\0';
    while( n-- > 0) {  //从后向前填充，这样避免常见新的变量做控制， 注意这里是n--
        pstr[n] = c;
    }
    return pstr;
}