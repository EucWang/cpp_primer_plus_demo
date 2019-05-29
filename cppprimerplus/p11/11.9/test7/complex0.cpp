#include <iostream>
#include "complex0.h"

/**
 * 构造函数
 */ 
complex::complex(){
    real = 0.0;
    imaginary = 0.0;
}

/**
 * 构造函数2
 */ 
complex::complex(double real, double imaginary){
    (*this).real = real;
    (*this).imaginary = imaginary;
 }
/**
 * 析构函数
 */ 
complex::~complex(){}

/**
 * 
 */ 
complex complex::operator+(complex & c2){
    return complex(real + c2.real , imaginary + c2.imaginary);
}

complex complex::operator-(complex & c2){
    return complex(real - c2.real , imaginary - c2.imaginary);
}

complex complex::operator*(complex & c2){
    double retReal = real * c2.real - imaginary * c2.imaginary;
    double retImg = real * c2.imaginary + imaginary * c2.real;
    return complex(retReal, retImg);
}

complex complex::operator*(double x){
    return complex(x * real, x* imaginary);
}

complex operator*(double x, complex & c) {
    return c*x;
}

complex operator~(complex & c) {
    return complex(c.real, -c.imaginary);
}

std::ostream & operator<<(std::ostream & os, complex & c){
    os<< "(" << c.real << ", " << c.imaginary << ")";
    return os;
}

std::istream & operator>>(std::istream & is, complex & c) {
    std::cout << "real:";
    is >> c.real;
    std::cout << "imaginary:";
    is >> c.imaginary;
    return is;
}