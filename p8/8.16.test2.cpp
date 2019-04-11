#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar{
    char brand[40];
    double weight;
    int calories;
};

void setCandyBar(CandyBar& bar, const char * brand, double w, int c);

void showCandyBar(CandyBar& bar);

int main237()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    CandyBar bar;
    setCandyBar(bar, "Millennium Munch", 2.85, 350);
    showCandyBar(bar);
    
    cout<<endl;
    return 0;
}


void setCandyBar(CandyBar& bar, const char * brand, double w, int c){
    strcpy(bar.brand, brand);
    bar.weight = w;
    bar.calories = c;
}

void showCandyBar(CandyBar& bar) {
    cout << "======CandyBar info======" << endl;
    cout << "[ brand : " << bar.brand << "\n  weight : "<< bar.weight 
        << "\n  calories : " << bar.calories << endl << "]" << endl;
}
