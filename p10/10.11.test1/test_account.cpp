#include <iostream>
#include "account.h"
using namespace std;

int main271()
{
    Account zhangsan("zhang san", "423534564563452", 1000);
    cout << "create account and then show info : "<<endl;
    zhangsan.show();

    zhangsan.save(1000);
    cout << "after save money, show info :" << endl;
    zhangsan.show();

    bool retVal = zhangsan.withdraw(500);
    if(retVal) {
        cout << "Withdraw money success." << endl;
    }else {
        cout << "withdraw money fail." << endl;
    }
    zhangsan.show();



    return 0;
}
