#include <iostream>
#include <cctype>
#include "stack.h"
using namespace std;



int main()
{
    double total_payment = 0.0;
    Stack st;
    char ch;
    // unsigned long po;
    Item po;
    cout << "Please enter A to add a purchase order," << endl
         << "P to process a PO, or Q to quit." << endl;

    while(cin >> ch && toupper(ch) != 'Q'){
        while(cin.get() != '\n') {
            continue;
        }
        if(!isalpha(ch)) {
            cout << "\a";
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                Item tmp;
                cin.clear();
                cout << "Enter a PO number : ";
                double num;
                cin >> tmp.payment;
                cout << "Enter a name:";
                while(cin.get() != '\n') {
                    continue;
                }
                cin.getline(tmp.fullname, 35);

                if(st.is_full()) {
                    cout << "stack already full" << endl;
                } else {
                    st.push(tmp);
                }
                break;
            case 'P':
            case 'p':
                if(st.is_empty()){
                    cout << "stack already empty" << endl;
                } else {
                    st.pop(po);
                    total_payment += po.payment;
                    cout << "PO #" << po.fullname <<  "," << po.payment << " popped" << endl;
                    cout << "Total Payment : " << total_payment << endl;
                }
                break;
        }
         cout << "Please enter A to add a purchase order, " << endl
            << "P to process a PO, or Q to quit.\n"; 
    }
    cout <<"Bye" << endl;

    return 0;
}
