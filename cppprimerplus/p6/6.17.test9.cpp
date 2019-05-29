#include <iostream>
#include <fstream>

struct DonationItem {
    char name[32];
    double donation;
};

int main94()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    ifstream inFile;
    inFile.open("donation_info.txt");
    if (!inFile.is_open()) {
        cout << "open file error. exit.";
        exit(-1);
    }
    
    int size;
    inFile >> size;

    if (inFile.good()) {
        inFile.get();
        DonationItem * items = new DonationItem[size];

        for(int i = 0; i < size; i++) {
            inFile.get(items[i].name, 32);
            inFile >> items[i].donation;
            inFile.get();
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
    }
    
  
    

    
    cout<<endl;
    return 0;
}
