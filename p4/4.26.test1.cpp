#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char * get_name0(){
    char tmp[256];
    cin.getline(tmp, 256);
    char * ret_val = new char(strlen(tmp) + 1);
    strcpy(ret_val, tmp);
    return ret_val;
}

int main13()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string tip1 = "What is your first name? ";
    string tip2 = "What is your last name? ";
    string tip3 = "What letter grade do you deserve? ";
    string tip4 = "What is your age? ";

    cout << tip1;
    char * first_name = get_name0();

    cout << tip2;
    char * last_name = get_name0();

    cout << tip3;
    char grade;
    cin >> grade;
    grade++;

    cout << tip4;
    int age =  -1;
    cin >> age;

    cout << "Name : " << first_name  << " " << last_name << endl;
    cout << "Grade : " << grade << endl;
    cout << "Age : " << age << endl;
    
    cout<<endl;
    return 0;
}
