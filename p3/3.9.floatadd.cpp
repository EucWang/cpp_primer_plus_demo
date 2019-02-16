#include <iostream>


int main()
{
    using namespace std;
    float a = 2.34e+22f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;

    //float 智能表示浮点数的前6-7数字，这个b比a大1， 但是a和b的位数有23位数字之多，最后一位被忽略了 ，所以这里输出0
    cout << "b - a = " << (b - a) << endl;

    return 0;
}
