#include <iostream>

/*
 * 
 * 文件结尾条件 
 * 检测文件尾EOF  （很多PC都将Ctrl+Z视为模拟的EOF）
 * 检测到EOF后，cin将两位（eofbit和failbit）都设置为1.
 * 可以通过成员函数eof()来查看eofbit是否被设置，如果检测到EOF，则cin.eof()将返回true，否则返回false.
 * 同样， 如果eofbit failbit被设置为1，则fail()成员函数返回true，否则返回false
 * 因此应将cin.eof() cin.fail()测试放在读取后
 * fail()相比于eof()，可以用于更多的实现，
 */ 
int main250()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
	
    cout << "Enter Ctrl+Z to finish your input action!!";
	char ch;
	int count = 0;
	// cin.get(ch);
	// while(cin.fail() == false)  //检测如果
	// {
	// 	cout << ch;
	// 	++count;
	// 	cin.get(ch);
	// }

    //更简洁的方式
    // cin.get(char)的返回值是一个cin对象。
    //然后istream类提供了一个可以将istream对象转换为bool值的函数
    //当cin出现在需要bool值的地方时，该转换函数将被调用。
    //另外，如果最后一个读取成功，则转换得到bool值为true，否则为false
    while(cin.get(ch))
    {
        cout << ch;
        ++count;
    }

	cout << endl << count << " characters read\n";

    cout<<endl;
    return 0;
}
