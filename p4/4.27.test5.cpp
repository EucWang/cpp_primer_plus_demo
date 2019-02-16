#include <iostream>

struct CandyBar 
{
    char band[64];
    double weight;
    int calories;
};

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    //初始化结构
    struct CandyBar snack = {"1", 2.3, 90};

    cout << snack.band << endl << snack.weight << endl << snack.calories << endl;

    struct CandyBar snacks[3] =
     {{"Mocha Munch", 2.3, 350},
     {"Natie", 2.4, 400},
     {"Bikini", 2.5, 450}};

    cout << "[" << snacks[0].band << "," << snacks[0].weight << ","  << snacks[0].calories << "]" << endl;
    cout << "[" << snacks[1].band << ","  << snacks[1].weight << ","  << snacks[1].calories << "]" << endl;
    cout << "[" << snacks[2].band << ","  << snacks[2].weight << ","  << snacks[2].calories << "]" << endl;
    
    cout<<endl;
    return 0;
}
