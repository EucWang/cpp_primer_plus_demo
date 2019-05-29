#include <iostream>
// #include <array>
// #include <string>

using namespace std;

const int Seasons2 = 4;

// const array<string, Seasons> Snames = {"Spring", "Summer", "Fail", "Winte"};
const char *  Snames2[Seasons2] = {"Spring", "Summer", "Fail", "Winte"};
// const string Snames[Seasons] = {"Spring", "Summer", "Fail", "Winte"};

// void fill(array<double, Seasons> * pa);
void fill(double * pa, int size);

// void show(array<double, Seasons> * da);
void show(double * da, int size);

int main276()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    // array<double, Seasons> expenses;
    double expenses[Seasons2];
    fill(expenses, Seasons2);
    show(expenses, Seasons2);
    
    cout<<endl;
    return 0;
}

// void fill(array<double, Seasons> * pa) {
void fill(double * pa, int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter " <<Snames2[i] << " expenses: ";
        // cin >> (*pa)[i];
        cin >> *(pa+i);
    }
}

// void show(array<double, Seasons> * da) {
void show(double * da, int size) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < size; i++) {
        cout << Snames2[i] << ": $" << *(da + i) << endl;
        total += *(da + i);
    }
    cout << "Total Expenses: $" << total << endl;
}
