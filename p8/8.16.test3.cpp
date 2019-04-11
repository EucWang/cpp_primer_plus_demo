#include <iostream>
#include <string>
// #include <cstring>

using namespace std;

void str_upper(string& str);

int main247()
{
    string tmp;
    cout << "Enter a string(q to quit) : ";
    while(true) {
        getline(cin, tmp);
        if(tmp == "q") {
            break;
        }
        // while(cin.get() != '\n') continue;
        str_upper(tmp);
        cout << tmp << endl;
        cout << "Next string(q to quit) : ";
    }
    
    return 0;
}

void str_upper(string& str) {
    int i=0;
    cout << str << endl;
    while(str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}
