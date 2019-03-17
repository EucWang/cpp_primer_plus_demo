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

void addMin(Time & t, int m) {
    t.minutes += m;
    t.hours += (t.minutes/60);
    t.minutes = (t.minutes%60);
}

void addHr(Time & t, int h) {
    t.hours += h;
}

void reset(Time & t, int h, int m) {
    t.hours = h;
    t.minutes = m;
}

Time operator+(Time & t0, const Time & t) {
    Time retVal;
    retVal.hours = t0.hours + t.hours + (t0.minutes + t.minutes)/60;
    retVal.minutes = (t0.minutes + t.minutes) %60;
    return retVal;
}

Time operator-(Time & t0, const Time & t) {
    Time diff;
    int tot1, tot2;
    tot2 = t0.hours * 60 + t0.minutes;
    tot1 = t.hours * 60 + t.minutes;
    diff.minutes = (tot2 - tot1) & 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(Time & t, double mult) {
    Time result;
    long totalMinutes = t.hours * 60 * mult + t.minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

// void Time::show() const{
//     std::cout << "====Time====" << std::endl;
//     std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
// }

Time operator*(double mult ,const Time & t) {
    Time result;
    long totalMinutes = t.hours * 60 * mult + t.minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os<< "Time[hours : " << t.hours << ", minutes : " << t.minutes << "]" << std::endl;
    return os;
}