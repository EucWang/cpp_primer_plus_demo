#include <iostream>

/**
 * cin.get(str, size); //读取一行内容到str中，长度为size，但是不再丢弃换行符，而是将其留在输入队列中
 * cin.get(); //读取一个字符
 * 
 * cin.get(name, arSize).get();
 * 第一个get()得到输入的内容，
 * 第二个get()消费掉留在输入队列中的换行符，
 * 防止影响下一次输入内容
 * 
 */ 

int main153()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    const int arSize = 20;
    char name[arSize];
    char dessert[arSize];

    cout << "Enter your name:\n";
    //第一个get()得到输入的内容，第二个get()消费掉留在输入队列中的换行符，防止影响下一次输入内容
    cin.get(name, arSize).get();

    cout <<"Enter your favorite dessert:\n";
    cin.get(dessert, arSize).get();

    cout << "I have some delicious "<< dessert;
    cout << " for you, "<< name <<".\n";


    cout<<endl;
    return 0;
}
