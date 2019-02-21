#include <iostream>
#include "coordin.h"

using namespace std;


int main(){
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;
    rect rplace;
    polar pplace;
    
    cout << "Enter the x and y values: ";
    while(cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit):";
    }
    cout << "Bye!!\n";

    //cout<<endl;
    return 0;
}
