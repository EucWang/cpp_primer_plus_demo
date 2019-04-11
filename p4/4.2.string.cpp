#include <iostream>
#include <cstring> //for the strlen() function

/**
 * sizeof() 计算的是数组长度
 * strlen() 计算的是存储再数组中的字符串长度
 */ 

int main2()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    const int size = 15;

    char name[size];
    char name2[size] = "C++owboy";

    cout << "Howdy! I'm " << name2;

    cout << "! What's your name?\n";

    cin >> name;

    cout << "Well," << name << ", your name has " 
        << strlen(name) << " letters and is stored\n";

    cout << "in an array of " << sizeof(name) << ". \n"
        << "Your initial is " << name[0] << endl;

    name2[3] = '\0';

    cout << "Here are the first 3 characters of my name:";
    cout << name2 << endl;


    cout<<endl;
    return 0;
}
