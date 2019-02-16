#include <iostream>
#include <string>

/**
 * string对象
 * 
 * 必须包含 <string>
 * string类位于名字空间std中，必须包含一条using编译指令
 * 
 * string类定义隐藏了字符串的数组性质，让您能够像处理普通变量那样处理字符串
 * 和字符串数组相同的地方：
 * 使用string对象的方式与使用字符数组相同
 * 可以使用 C风格字符串来初始化string对象
 * 可以使用cin来将输入存储到string对象中
 * 可以使用cout 来显示string对象
 * 可以使用数组表示法来访问存储再string对象中的字符。
 * 
 * 和字符串数组不相同的地方：
 * 可以将string对象声明为简单变量，而不是数组
 * string对象可以自动处理大小，比数组方便
 * 
 */ 

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char charr1[20];
    char charr2[20] = "jaguar";

    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline: ";
    cin >> charr1;

    cout << "Enter another kind of feline:";
    cin >> str1;

    cout << "Here are some felines:\n";

    cout << charr1 << " " << charr2 << " "
        << str1 << " " << str2 << endl;

    cout << "The third letter in " << charr2 << " is "
        << charr2[2] << endl;

    cout << "The third letter in " << str2 << " is "
        << str2[2] << endl;

    cout<<endl;
    return 0;
}
