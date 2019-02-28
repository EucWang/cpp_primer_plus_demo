#include "mytime1.h"
#include <iostream>

Time::Time(){
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::addMin(int m) {
    minutes += m;
    hours += (minutes/60);
    minutes = (minutes%60);
}

void Time::addHr(int h) {
    hours += h;
}

void Time::reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const {
    Time retVal;
    retVal.hours = hours + t.hours + (minutes + t.minutes)/60;
    retVal.minutes = (minutes + t.minutes) %60;
    return retVal;
}

void Time::show() const{
    std::cout << "====Time====" << std::endl;
    std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
}