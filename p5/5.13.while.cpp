#include <iostream>
#include <string>

const int ArSize = 20;
int main20()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char name[ArSize];

    string tip1 = "Your first name, please : ";
    string tip2 = "Here is your name, verticalized and ASCIIized:\n";

    cout << tip1;
    cin >> name;
    cout << tip2;
    int i=0;
    while(name[i] != '\0'){
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
    
    cout<<endl;
    return 0;
}
