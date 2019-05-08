#include "customer2.h"
#include <iostream>

using namespace std;

void Customer2::set(long when) {
    processtime = rand() % 3 + 1;
    arrive = when;
}

std::ostream & operator<<(std::ostream & os, Customer2 & c) {
    os << "Customer2 [ processtime : " << c.processtime << ", " << "arrive : "<< c.arrive << "]" << endl;
    return os;
}