/* 演示如何使用无符号类型， 超越整形时，数据溢出之后的结果*/
#include <iostream>
#include <climits>

#define ZERO 0

int main161()
{
    using namespace std;

    short sam = SHRT_MAX;

    unsigned short sue = sam;

    cout << "sam has " << sam << " dollars and Sue has " << sue
        << " dollars deposited." << endl
        << "Add $1 to each count." << endl;

    sam ++;
    sue ++;

    cout << "sam has " << sam << " dollars and Sue has " << sue
        << " dollars deposited." << endl << "Poor sam!" << endl;

    cout << "===========================" << endl;

    sam = ZERO;
    sue = ZERO;

    cout << "sam has " << sam << " dollars and Sue has " << sue
        << " dollars deposited." << endl 
        << "Take $1 from each count." << endl;

    sam--;
    sue--;

    cout << "sam has " << sam << " dollars and Sue has " << sue
        << " dollars deposited." << endl 
        << "Lucky sue!!" << endl;

    return 0;
}