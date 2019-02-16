#include <iostream>
#include <string>
#include <cstring>

/**
 * string类i/o
 * 
 * getline()函数是isteam 类的一个类方法（cin是一个istream对象）
 * 将键盘输入保存到字符串数组中
 * cin.getline(charr, 20);
 * 
 * 将键盘输入存储到字符串对象中，这里的getline()方法不是类方法
 * getline(cin, str);
 * 
 * 如下字符串处理类型，需要后续再学习，不懂
 * wchar_t
 * char16_t
 * char32_t
 * utf8 
 * R"(Jim "King" Tutt uses "\n" instead of endl.)" 
 */
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char charr[20];
    string str;

    cout << "Length of string in charr before iniput: "
        << strlen(charr) <<endl;

    cout << "Length of string in str before input: "
        << str.size() << endl;

    cout << "Enter a line of text :\n";
    // getline()函数是isteam 类的一个类方法（cin是一个istream对象） 
    cin.getline(charr, 20);   //将键盘输入保存到字符串数组中

    cout << "You entered : " << charr << endl;
    cout << "Enter another line of text:\n";

    //这里的getline()方法不是类方法
    getline(cin, str);   //将键盘输入存储到字符串对象中

    cout << "You entered : " << str << endl;
    cout << "Length of string in charr after input : "
        << strlen(charr) << endl;   

    cout << "Length of string in str after input : " 
        << str.size() << endl;

    wchar_t title[] = L"Chief Astrogator";
    // char16_t name[] = u"Felonia Ripova";
    // char32_t car[] = U"Humber Super Snipe";

    // char32_t utf8chararr = u8"中华人民共和国";

    cout << "wchar_t char array is : " << title << endl;

    string utf8str = "中华人民共和国";

    // cout << "utf8 string : " << utf8str << " , size is : " << utf8str.size();

    // cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';

    cout<<endl;
    return 0;
}