#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;

const array<string, Seasons> Snames = {"Spring", "Summer", "Fail", "Winte"};

void fill(array<double, Seasons> * pa);

void show(array<double, Seasons> * da);

int main286()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    array<double, Seasons> expenses;
    fill(&expenses);
    show(&expenses);
    
    cout<<endl;
    return 0;
}

void fill(array<double, Seasons> * pa) {
    for(int i = 0; i < Seasons; i++) {
        cout << "Enter " <<Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(array<double, Seasons> * da) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << (*da)[i] << endl;
        total += (*da)[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
