#include <iostream>
using namespace std;

//全局变量
double warming = 0.3;

void update(double dt);

void local();


int main225()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);

    cout << "Global warming is " << warming << " degrees.\n";
    local();

    cout << "Global warming is " << warming << " degrees.\n";
    //cout<<endl;
    return 0;
}
