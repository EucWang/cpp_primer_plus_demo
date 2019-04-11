#include <iostream>


int main34()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;
    
    int count = 0;
    int num = 0;

    do{
        cout << "Please enter a number(input 0 to eixt) :";
        cin >> num;
        if (num == 0) {
            break;
        }
        count += num;
        cout << "till now count of your input number is :" << count << endl << endl;
    }while(true);
    return 0;
}
