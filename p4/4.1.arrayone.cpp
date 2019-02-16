#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int yams[3];

    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 9;

    int yamcosts[3] = {20, 30, 5};

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;

    cout << yamcosts[1] << " cents per yam.\n";

    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];

    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;

    cout << " bytes.\n";

    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n"; 

    cout<<endl;
    return 0;
}
