#include <iostream>
#include <string>
#include <cstring>

struct CandyBar 
{
    char band[64];
    double weight;
    int calories;
};

int main4()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

//const struct CandyBar * bars[3] =
    struct CandyBar * bars =  new struct CandyBar[3];
    strcpy(bars->band, "Mocha Munch");
    bars->weight = 2.3,
    bars->calories = 350;

    strcpy((bars+1)->band, "Natie");
    (bars+1)->weight = 2.4,
    (bars+1)->calories = 400;

    strcpy((bars+2)->band, "Natie");
    (bars+2)->weight = 2.4,
    (bars+2)->calories = 450;
 
    cout << "[" << bars[0].band << "," << bars[0].weight << ","  << bars[0].calories << "]" << endl;
    cout << "[" << bars[1].band << ","  << bars[1].weight << ","  << bars[1].calories << "]" << endl;
    cout << "[" << bars[2].band << ","  << bars[2].weight << ","  << bars[2].calories << "]" << endl;
    
    cout<<endl;
    return 0;
}
