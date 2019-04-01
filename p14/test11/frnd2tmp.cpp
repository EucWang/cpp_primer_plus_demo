#include <iostream>
#include "hasFriend.h"

using std::cout;
using std::endl;

int main(){

    cout << "No objects declared: \n";
    counts();

    HasFriend<int> hfil(10);
    cout << "After hfil declared:  \n";
    counts();

    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared:  \n";
    counts();

    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared:  \n" ;
    counts();

    reports(hfil);
    reports(hfi2);
    reports(hfdb);

    return 0;
}
