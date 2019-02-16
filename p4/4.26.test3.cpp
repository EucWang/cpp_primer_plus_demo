#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char * get_name(){
    char tmp[256];
    cin.getline(tmp, 256);
    char * ret_val = new char(strlen(tmp) + 1);
    strcpy(ret_val, tmp);
    return ret_val;
}

int main()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string tip1 = "Enter your first name : ";
    string tip2 = "Enter your last name : ";
    string tip3 = "Here's the information in a single string : ";

    cout << tip1;
    char * first_name;
    first_name = get_name();

    cout << tip2;
    char * last_name;
    last_name = get_name();

    int count = strlen(first_name) + strlen(last_name) + 3;

    char * full_name = new char(count);

    strcpy(full_name, first_name);
    *(full_name + strlen(first_name)) = ',';
    *(full_name + strlen(first_name) + 1) = ' ';
    strcpy((full_name + strlen(first_name) + 2), last_name);
    cout << tip3 << full_name;
    
    cout<<endl;
    return 0;
}
