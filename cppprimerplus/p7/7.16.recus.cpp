#include <iostream>

/**
 * 递归调用， 倒数数
 */ 
void countdown(int n);

using namespace std;

int main83()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    countdown(4);
    cout<<endl;
    return 0;
}

void countdown(int n) {
    cout << "Counting down ..." << n << endl;
    if(n>0){
        countdown(n-1);
    }
    cout << n << ": Kaboom!\n";
}
