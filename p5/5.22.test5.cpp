#include <iostream>


int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;

    const char * month_name[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int sale_month_count[12];
    int total;

    for(int i = 0; i < 12; i++)
    {
        cout << "Please enter sale count of " << month_name[i] << " : ";
        cin >> sale_month_count[i];
        total += sale_month_count[i];
    }
    cout << "total sale value is " << total << endl;
    

    // cout<<endl;
    return 0;
}
