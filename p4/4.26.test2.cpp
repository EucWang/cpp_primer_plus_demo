#include <iostream>
#include <string>
using namespace std;

char * get_name(){
    char tmp[256];
    cin.getline(tmp, 256);
    char * ret_val = new char(strlen(tmp) + 1);
    strcpy(ret_val, tmp);
    return ret_val;
}

int main() {
   
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    const int arSize = 20;
    // char name[arSize];
    // char dessert[arSize];
    string name;
    string dessert;

    cout << "Enter your name:\n";
    // cin.getline(name, arSize); //reads through newline
    // cin >> name;
    name = get_name();

    cout << "Enter your favorite dessert:\n";
    // cin.getline(dessert, arSize);
    // cin >> dessert;
    dessert = get_name();

    cout << "I have some delicious "<< dessert;
    cout << " for you, " << name << ".\n";

    cout<<endl;
    return 0;
}