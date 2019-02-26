#include <iostream>
#include "sales.h"

using namespace std;
using namespace SALES;

int main()
{
    cout.setf(ios_base::fixed);
    cout.precision(3);

    Sales s1;
    Sales s2;

    s1.setSales();
    s1.showSales();

    const double ar[4] ={1.1, 2.2, 3.3, 4.4};
    s2.setSales(ar, 3);
    s2.showSales();
    return 0;
}
