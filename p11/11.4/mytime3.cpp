#include "mytime3.h"
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

Time Time::operator-(const Time & t) const {
    Time diff;
    int tot1, tot2;
    tot2 = hours * 60 + minutes;
    tot1 = t.hours * 60 + t.minutes;
    diff.minutes = (tot2 - tot1) & 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const {
    Time result;
    long totalMinutes = hours * 60 * mult + minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

// void Time::show() const{
//     std::cout << "====Time====" << std::endl;
//     std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
// }

Time operator*(double m ,const Time & t) {
    return t*m;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os<< "Time[hours : " << t.hours << ", minutes : " << t.minutes << "]" << std::endl;
    return os;
}