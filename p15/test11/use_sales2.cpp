#include <iostream>
#include "../test5/sales.h"
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

const double vals10[12] = {
    1220, 1100, 1122, 2212, 1232, 2334,
    2884, 2393, 3302, 2922, 3002, 3544
};

const double vals20[12] = {
    12, 11, 22, 21,32,34,
    28, 29, 33, 29, 32, 35
};

int main_sales2(){
    Sales sales1(2011, vals10, 12);
    LabeledSales sales2("Blogstar", 2012, vals20, 12);

    cout << "First try block:\n";
    try{
        int i;
        cout << "Year = " << sales1.getYear() << endl;
        for(i=0; i<12; i++) {
            cout << sales1[i] << " ";
            if(i%6 == 5) {
                cout << endl;
            }
        }

        cout << "\n----------\n";
        cout << "Year = " << sales2.getYear() << endl;
        cout << "Label = " << sales2.getLabel() << endl;
        for(i=0; i<=12; i++) {
            cout << sales2[i] << " ";
            if(i%6 == 5) {
                cout << endl;
            }
        }
        cout << "End of try block 1.\n"; 
    }catch(Sales::BadIndex & bad) {
        cout << bad.what();
        cout << "Bad Index : " << bad.getBiVal() << endl;

        if(typeid(LabeledSales::NbadIndex) == typeid(bad)) {
            LabeledSales::NbadIndex & nb = dynamic_cast< LabeledSales::NbadIndex &>(bad);
            cout << "Company : " << nb.getLabelVal() << endl;
        }
    }

    cout << "\n============================\n";
    cout << "\n============================\n";
    cout << "\nNext try block:\n";
    try {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of try block 2.\n";
    }catch(Sales::BadIndex & bad) {
        cout << bad.what();
        cout << "Bad Index : " << bad.getBiVal() << endl;

        if(typeid(LabeledSales::NbadIndex) == typeid(bad)) {
            LabeledSales::NbadIndex & nb = dynamic_cast< LabeledSales::NbadIndex &>(bad);
            cout << "Company : " << nb.getLabelVal() << endl;
        }
    }

    cout << "Done.\n";
    return 0;
}