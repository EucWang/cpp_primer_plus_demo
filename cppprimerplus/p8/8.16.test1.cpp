#include <iostream>
using namespace std;

void print_str(const char * str, int n=1);

int main96()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    print_str("Wahaha");

    print_str("waiting for my favorite song.", 3);

    cout<<endl;
    return 0;
}

void print_str(const char * str, int n) {
    if(n <= 1) {
        cout << str << endl;
    }else {
        cout << str << endl;
        print_str(str, n-1);
    }

}