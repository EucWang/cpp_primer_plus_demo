#include "mytime2.h"
#include <iostream>

Time2::Time2(){
    hours = 0;
    minutes = 0;
}

Time2::Time2(int h, int m) {
    hours = h;
    minutes = m;
}

void Time2::addMin(int m) {
    minutes += m;
    hours += (minutes/60);
    minutes = (minutes%60);
}

void Time2::addHr(int h) {
    hours += h;
}

void Time2::reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time2 Time2::operator+(const Time2 & t) const {
    Time2 retVal;
    retVal.hours = hours + t.hours + (minutes + t.minutes)/60;
    retVal.minutes = (minutes + t.minutes) %60;
    return retVal;
}

Time2 Time2::operator-(const Time2 & t) const {
    Time2 diff;
    int tot1, tot2;
    tot2 = hours * 60 + minutes;
    tot1 = t.hours * 60 + t.minutes;
    diff.minutes = (tot2 - tot1) & 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time2 Time2::operator*(double mult) const {
    Time2 result;
    long totalMinutes = hours * 60 * mult + minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

void Time2::show() const{
    std::cout << "====Time====" << std::endl;
    std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
}