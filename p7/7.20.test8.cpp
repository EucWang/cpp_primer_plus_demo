#include <iostream>
// #include <array>
// #include <string>

using namespace std;

const int Seasons = 4;

// const array<string, Seasons> Snames = {"Spring", "Summer", "Fail", "Winte"};
const char *  Snames[Seasons] = {"Spring", "Summer", "Fail", "Winte"};
// const string Snames[Seasons] = {"Spring", "Summer", "Fail", "Winte"};

// void fill(array<double, Seasons> * pa);
void fill(double * pa, int size);

// void show(array<double, Seasons> * da);
void show(double * da, int size);

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    // array<double, Seasons> expenses;
    double expenses[Seasons];
    fill(expenses, Seasons);
    show(expenses, Seasons);
    
    cout<<endl;
    return 0;
}

// void fill(array<double, Seasons> * pa) {
void fill(double * pa, int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter " <<Snames[i] << " expenses: ";
        // cin >> (*pa)[i];
        cin >> *(pa+i);
    }
}

// void show(array<double, Seasons> * da) {
void show(double * da, int size) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < size; i++) {
        cout << Snames[i] << ": $" << *(da + i) << endl;
        total += *(da + i);
    }
    cout << "Total Expenses: $" << total << endl;
}
