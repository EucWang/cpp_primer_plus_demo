#include <iostream>


int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    double cups = 4.5;
    int donuts = 6;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;

    cout << "cups = " << cups << " and cups address = " << &cups << endl;

    cout<<endl;
    return 0;
}
