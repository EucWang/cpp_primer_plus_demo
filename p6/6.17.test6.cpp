#include <iostream>
#include <string>
#include <array>

struct DonationItem {
    char name[32];
    double donation;
};

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int size;
    cout << "Please enter size : ";
    while(!(cin >> size)){
        cout << "Please enter a number: ";
    }
    cin.get();

    struct DonationItem * items = new DonationItem[size];
    
    for(int i = 0; i < size; i++) {
        cout << "Please enter a Patron info: " << endl;
        cout << "Please enter person name : ";
        cin.getline(items[i].name, 32);
        cout << "Please enter donation value : ";
        cin >> items[i].donation;
        cin.get();
    }

    cout << "\n=========\nGrand Patrons List : " << endl;
    int total =0;
    for(int i = 0; i < size; i++) {
        if (items[i].donation > 10000) {
            cout << items[i].name << ", " <<items[i].donation << endl;
            total++;
        }
    }
    if (total == 0) {
        cout << "none\n";
    }
    
    cout << "\n=========\nPatrons List : " << endl;
    total = 0;
    for(int i = 0; i < size; i++) {
        if (items[i].donation <= 10000) {
            cout << items[i].name << ", " <<items[i].donation << endl;
            total++;
        }
    }
    if (total == 0) {
        cout << "none\n";
    }
    
    cout<<endl;
    return 0;
}
