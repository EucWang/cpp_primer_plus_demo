#include <iostream>
#include <string>


int main9()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;


    string tip1 = "Enter your first name : ";
    string tip2 = "Enter your last name : ";
    string tip3 = "Here's the information in a single string : ";

    cout << tip1;
    string first_name;
    cin >> first_name;

    cout << tip2;
    string last_name;
    cin >> last_name;

    //string对象直接使用"+“进行拼接
    string full_name(first_name + ", " + last_name);
    cout << tip3 << full_name;
    
    cout<<endl;
    return 0;
}
