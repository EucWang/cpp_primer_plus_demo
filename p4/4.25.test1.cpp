#include <iostream>
#include <array>
#include <string>

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char actor[30] = "hello there";

    short betsie[100];

    float chuck[13];

    long double dipsea[64];

    array<char, 30> actor2;
    array<short, 100> betsie2;
    array<float, 13> chuck2;
    array<long double, 64> dipsea2;


    int intarr[5] = {1,2, 3, 5,7};
    int even = intarr[0] + intarr[4];
    cout << "even : " << even << endl;

    float ideas[3] = {1,2,3};
    cout <<"ideas[1] = " << ideas[1] << endl;

    const char * cheeseburger = "cheeseburger";
    cout << "cheeseburger : " << cheeseburger << endl;

    string waldorf = "Waldorf Salad";
    cout << "waldorf : " << waldorf << endl;

    cout<<endl;
    return 0;
}
