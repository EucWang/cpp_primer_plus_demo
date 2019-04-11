#include "mytime3.h"
#include <iostream>

Time94::Time94(){
    hours = 0;
    minutes = 0;
}

Time94::Time94(int h, int m) {
    hours = h;
    minutes = m;
}

void addMin(Time94 & t, int m) {
    t.minutes += m;
    t.hours += (t.minutes/60);
    t.minutes = (t.minutes%60);
}

void addHr(Time94 & t, int h) {
    t.hours += h;
}

void reset(Time94 & t, int h, int m) {
    t.hours = h;
    t.minutes = m;
}

Time94 operator+(Time94 & t0, const Time94 & t) {
    Time94 retVal;
    retVal.hours = t0.hours + t.hours + (t0.minutes + t.minutes)/60;
    retVal.minutes = (t0.minutes + t.minutes) %60;
    return retVal;
}

Time94 operator-(Time94 & t0, const Time94 & t) {
    Time94 diff;
    int tot1, tot2;
    tot2 = t0.hours * 60 + t0.minutes;
    tot1 = t.hours * 60 + t.minutes;
    diff.minutes = (tot2 - tot1) & 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time94 operator*(Time94 & t, double mult) {
    Time94 result;
    long totalMinutes = t.hours * 60 * mult + t.minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

// void Time94::show() const{
//     std::cout << "====Time94====" << std::endl;
//     std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
// }

Time94 operator*(double mult ,const Time94 & t) {
    Time94 result;
    long totalMinutes = t.hours * 60 * mult + t.minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time94 & t){
    os<< "Time94[hours : " << t.hours << ", minutes : " << t.minutes << "]" << std::endl;
    return os;
}