#include <iostream>

int stoneToLb(int sts);

int main()
{

    using namespace std;

    int stone;

    cout << "Enter the weight in stone:" << endl;
    cin >> stone;

    int pounds = stoneToLb(stone);

    cout << stone << " stones = ";
    cout << pounds << " pounds." << endl;



}

int stoneToLb(int sts) 
{
    return 14 * sts;
}