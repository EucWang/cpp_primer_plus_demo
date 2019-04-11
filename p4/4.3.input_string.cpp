#include <iostream>

/**
 * cin输入的限制：
 * cin 输入字符串时，中间不能包含空格，
 * cin 使用空白（空格，制表符，换行符）来确定字符串的结束
 * cin的另外一个问题输入内容可能比是目标数组长度长
 * 
 */ 

int main71()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    const int arSize = 20;

    char name[arSize];
    char dessert[arSize];

    cout << "Enter your name:\n";
    cin >> name;  //请输入内容“Alistair Dreeb”

    cout << "Enter your favorite dessert:\n";
    cin >> dessert;

    cout << "I have some delicious "<< dessert;
    cout << " for you, " << name <<".\n";

    cout<<endl;
    return 0;
}
