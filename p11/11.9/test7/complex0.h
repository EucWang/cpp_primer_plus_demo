#ifndef COMPLEX_0_H_

#define COMPLEX_0_H_

#include <iostream>

class complex {
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double real, double imaginary);
        ~complex();

    complex operator+(complex & c2);
    complex operator-(complex & c2);
    complex operator*(complex & c2);
    complex operator*(double x);
    // complex operator~();

    friend complex operator*(double x, complex & c);
    friend std::ostream & operator<<(std::ostream & os, complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
    friend complex operator~(complex & c);
};


#endif