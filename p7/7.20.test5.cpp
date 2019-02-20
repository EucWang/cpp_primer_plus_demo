#include <iostream>

unsigned long factorial(unsigned long n); 

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    unsigned long a;
    cout << "Enter a number and then calculate the factorial value " << endl;
    while(cin>>a) {
        cout << "factorial value is : " << factorial(a) << endl;
        cout << "Next number : " << endl;
    }
    cout << "Done";
    cout<<endl;
    return 0;
}

unsigned long factorial(unsigned long n){
    if(n == 0) { return 1;
    } else if(n == 1) {
         return 1;
    } else if(n == 2) {
        return 2;
    } else {
        return n * factorial(n - 1);
    }
}