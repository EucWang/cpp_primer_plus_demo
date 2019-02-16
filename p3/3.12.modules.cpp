#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << endl;

    const int Lbs_per_stn = 14;

    int lbs;
    cout << "Please enter your weight in ponds: ";
    cin >> lbs;

    int stone = lbs / Lbs_per_stn;
    int pounds = lbs % Lbs_per_stn;

    cout << lbs << " pounds are " << stone << " stone, " << pounds << " pounds(s). \n";

    cout << endl;
    return 0;
}
