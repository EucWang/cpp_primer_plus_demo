#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;
using std::string;

int main182(){

    Stack<string> st = Stack<string>();
    char ch;
    string po;
    cout << "Please enter A to add a purchase order.\n"
        << "P to process a PO, or Q to quit.\n";

    while(cin >> ch && std::toupper(ch) != 'Q') {
        while(cin.get() != '\n') {
            continue;
        }
        if(!std::isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add:";
                cin >> po;
                if(st.isfull()){
                    cout << "stack already full\n";
                }else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if(st.isempty()) {
                    cout << "stack already empty.\n";
                } else {
                    po = "-";
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                    break;
                }
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n ";
    }
    cout << "Bye.\n";
    return 0;
}