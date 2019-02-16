/**
 * 对于float， c++只保证6位有效数字
 * 对于float 的加减乘除
 */ 
#include <iostream>

int main()
{
    using namespace std;
    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Enter a number :";
    cin >> hats;
    cout << "\nEnter another number:";
    cin >> heads;

    cout << "hats + heads = " << hats + heads << endl;

    cout << "hats - heads = " << hats - heads << endl;

    cout << "hats * heads = " << hats * heads << endl;

    cout << "htas / heads = " << hats / heads << endl;

    return 0;
}
