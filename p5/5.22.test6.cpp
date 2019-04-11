#include <iostream>


int main17()
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

    int sale_val[3][12];
    int sale_year[3];
    for(int i = 0; i < 3; i++)
    {
        cout << "Please input " << (i+1) << " year's sale data : " << endl;
        for(int j = 0; j < 12; j++)
        {
            cout << "Please input " <<  month_name[j] << "'s sale data : ";
            cin >> sale_val[i][j];
            sale_year[i] += sale_val[i][j];
        }
    }
    int total;
    for(int i = 0; i< 3; i++) 
    {
        cout << "the " << (i + 1) << " year's total sale is : " << sale_year[i] << endl;
        total += sale_year[i];
    }
    cout << "the total count of 3 years value is : " << total << endl;
    
    // cout<<endl;
    return 0;
}
