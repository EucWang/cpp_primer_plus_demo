#include <iostream>
#include "sales.h"

using namespace std;
using namespace SALES;

int main229()
{
    Sales s1;
    Sales s2;

    setSales(s1);
    showSales(s1);

    const double ar[4] ={1.1, 2.2, 3.3, 4.4};
    setSales(s2, ar, 3);
    showSales(s2);
    return 0;
}
