#include <iostream>
#include <string>

/**
 * string的几个操作方式
 * 赋值，拼接，附加
 * 可以将一个string对象赋值另外一个string对象
 * 可以使用“+” 将两个string合并起来
 * 也可以使用“+=”将字符串附加到另外一个string对象的末尾。
 * 
 */ 

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    string s1 = "penguin";
    string s2, s3;

    cout <<"You can assign one string object to another: s2 = s1\n";
    s2 = s1;
    cout << "s1 : " << s1 << ", s2 : " << s2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = 'buzzard'\n";
    s2 = "buzzard";
    cout << "s2: " << s2 << endl;

    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;

    cout << "s3: " << s3 << endl;

    s1 += s2;
    cout << "s1 += s2 yields s1 = "<<s1 <<endl;

    s2 += " for a day";

    cout << "s2 += 'for a day' yields s2 = " << s2 << endl;

    cout<<endl;
    return 0;
}
