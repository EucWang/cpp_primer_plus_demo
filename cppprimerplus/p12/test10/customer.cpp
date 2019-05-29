#include "customer.h"
#include <iostream>

using namespace std;

void Customer1210::set(long when) {
    processtime = rand() % 3 + 1;
    arrive = when;
}

std::ostream & operator<<(std::ostream & os, Customer1210 & c) {
    os << "Customer1210 [ processtime : " << c.processtime << ", " << "arrive : "<< c.arrive << "]" << endl;
    return os;
}