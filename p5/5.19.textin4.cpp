#include <iostream>

int main22() {
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int ch;
    int count = 0;
    while((ch = cin.get()) != EOF){
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read" << endl;
    cout<<endl;
    return 0;
}
