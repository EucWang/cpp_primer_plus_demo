#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;    
};

int main87()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    inflatable bouquet = 
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;

    cout << "bouquet : " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;

    cout << "choice : " << choice.name << " for $";
    cout << choice.price << endl; 

    cout<<endl;
    return 0;
}
