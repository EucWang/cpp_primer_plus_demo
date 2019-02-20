#include <iostream>

using namespace std;

const int Seasons = 4;

struct Expenses{
    double val[Seasons];
};

const char *  Snames[Seasons] = {"Spring", "Summer", "Fail", "Winte"};

// void fill(double * pa, int size);
void fill(Expenses * ex);

// void show(double * da, int size);
void show(Expenses * ex);

int main()
{
    using namespace std;
    cout<<endl;
    // double expenses[Seasons];
    Expenses expenses;
    fill(&expenses);
    show(&expenses);
    
    cout<<endl;
    return 0;
}

void fill(Expenses * ex) {
    // for(int i = 0; i < sizeof(ex->val); i++) {
    for(int i = 0; i < Seasons; i++) {
        cout << "Enter " <<Snames[i] << " expenses: ";
        cin >> *(ex->val+i);
    }
}

void show(Expenses * ex) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << *(ex->val + i) << endl;
        total += *(ex->val + i);
    }
    cout << "Total Expenses: $" << total << endl;
}
