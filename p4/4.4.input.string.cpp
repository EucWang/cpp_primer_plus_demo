#include <iostream>

/**
 * cin.getline() 每次读取一行，它通过换行符确定行尾，但是不保存换行符
 * 相反，在存储字符串时，它用空字符替换换行符
 * 
 */ 
int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    const int arSize = 20;
    char name[arSize];
    char dessert[arSize];

    cout << "Enter your name:\n";
    cin.getline(name, arSize); //reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, arSize);
    cout << "I have some delicious "<< dessert;
    cout << " for you, " << name << ".\n";

    cout<<endl;
    return 0;
}
