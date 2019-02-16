#include <iostream>

/**
 * 
 * 混合输入数字和面向行的字符串会导致问题
 * 当cin读取数字时，会将回车键生成的换行符留在输入队列中，
 * 后面的cin.getline()看到换行符之后，将认为是一个空行，并将空字符串赋值
 * 
 * 解决方法，在于读取地址之前先读取并丢弃换行符
 * 
 */ 

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    cout <<"What year was your house built?\n";
    int year;

    cin >> year;
    // (cin >> year).get();
    cin.get();

    cout << "What is its street address?\n";

    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;

    cout << "Done!\n";

    cout<<endl;
    return 0;
}
