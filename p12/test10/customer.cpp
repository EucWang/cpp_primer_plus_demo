#include "customer.h"
#include <iostream>

using namespace std;

void Customer::set(long when) {
    processtime = rand() % 3 + 1;
    arrive = when;
}

std::ostream & operator<<(std::ostream & os, Customer & c) {
    os << "Customer [ processtime : " << c.processtime << ", " << "arrive : "<< c.arrive << "]" << endl;
    return os;
}