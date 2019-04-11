#include <iostream>



int main57()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;
    const double init_val = 100;
    double daphne = init_val;
    double cleo = init_val;

    int i=1;
    while(true){
        daphne  += init_val * 0.1;
        cleo += cleo * 0.05;
        if (cleo > daphne) {
            cout << "after " << i << " year, Cleo's money more than Daphne. " 
                << "\n Cleo's money is " << cleo
                << "\n Daphne's money is " << daphne << endl;
            break;
        }

        cout << "after " << i << " year " 
                << "\t Cleo's money is " << cleo
                << "\t Daphne's money is " << daphne << endl;


        i++;
    }
    return 0;
}
