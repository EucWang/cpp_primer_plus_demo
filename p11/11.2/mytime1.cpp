#include "mytime1.h"
#include <iostream>

Time1::Time1(){
    hours = 0;
    minutes = 0;
}

Time1::Time1(int h, int m) {
    hours = h;
    minutes = m;
}

void Time1::addMin(int m) {
    minutes += m;
    hours += (minutes/60);
    minutes = (minutes%60);
}

void Time1::addHr(int h) {
    hours += h;
}

void Time1::reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time1 Time1::operator+(const Time1 & t) const {
    Time1 retVal;
    retVal.hours = hours + t.hours + (minutes + t.minutes)/60;
    retVal.minutes = (minutes + t.minutes) %60;
    return retVal;
}

void Time1::show() const{
    std::cout << "====Time1====" << std::endl;
    std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
}