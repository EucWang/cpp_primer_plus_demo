/* 自定义函数 */
#include <iostream>

void simon(int);

int main176()
{

    using namespace std;

    simon(3);

    cout << "pickup a integer " << endl;

    int n;
    cin >> n;

    simon(n);

    cout << "DONE!" << endl;

    return 0;
}

void simon(int n) 
{
    using namespace std;

    cout << "Simon says touch your toes " << n << " times." << endl;
}