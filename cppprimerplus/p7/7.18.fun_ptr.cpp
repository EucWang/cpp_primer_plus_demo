#include <iostream>


double betsy(int);

double pam(int);

void estimate(int lines, double (*pf)(int));

int main279()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int code;
    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate: " << endl;
    estimate(code, betsy);

    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
    
    cout<<endl;
    return 0;
}

double betsy(int lns) {
    return 0.05 * lns;
}

double pam(int lns) {
    return 0.03 * lns + 0.0004 * lns * lns;
}

/**
 * 第二个参数接收一个函数指针，动态调用其他函数
 */ 
void estimate(int lines, double (*pf)(int)) {
    using namespace std;

    cout << lines << " lines will take "
        << (*pf)(lines) << " hour(s)\n";
}
