#include <iostream>


int main6()
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
    //可以将cin.getline(address, 80)替换成cin >> address, 
    //如果程序后面执行时还需要用户输入内容时，会导致输入失败，接收一个空字符串
    // cin.getline(address, 80);
    cin >> address;

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;

    cout << "Done!\n";

    cout<<endl;
    return 0;
}