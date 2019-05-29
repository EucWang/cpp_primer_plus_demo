#include <iostream>
#include <string>

int main54()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;
    
    string tmp;

    cout << "Enter words (to stop, type the word done):\n";
    int count = -1;
    do{
        cin >> tmp;
        count++;
    }while(tmp != "done");
    cout << "You entered a total of " << count << " words." << endl;
    // cout<<endl;
    return 0;
}
