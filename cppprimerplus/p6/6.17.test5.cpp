#include <iostream>


double tax(int tvarps) {
    if (tvarps < 5000) {
        return 0;
    }else {
        if (tvarps < 15000) {
           return (tvarps - 5000) * 0.1;
        }else {
            if (tvarps < 35000) {
                return 10000 * 0.1 + (tvarps - 15000) * 0.15;
            }else {
                return 10000 * 0.1 + 20000 * 0.15 + (tvarps - 35000) * 0.2;
            }
        }
    }
}

int main1178()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout<<endl;
    
    bool flag = true;
    int tvarps;
    cout << "Please enter your tvarps value : \n";
    while(flag && cin >> tvarps){
        if (tvarps <= 0) {
            break;
        }
        cout << "tax is " << tax(tvarps) << endl;   
        cout << "next tvarps : \n";     
    }

    cout<<endl;
    return 0;
}
