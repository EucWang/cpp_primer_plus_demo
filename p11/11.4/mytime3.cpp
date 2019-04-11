#include "mytime3.h"
#include <iostream>

Time3::Time3(){
    hours = 0;
    minutes = 0;
}

Time3::Time3(int h, int m) {
    hours = h;
    minutes = m;
}

void Time3::addMin(int m) {
    minutes += m;
    hours += (minutes/60);
    minutes = (minutes%60);
}

void Time3::addHr(int h) {
    hours += h;
}

void Time3::reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time3 Time3::operator+(const Time3 & t) const {
    Time3 retVal;
    retVal.hours = hours + t.hours + (minutes + t.minutes)/60;
    retVal.minutes = (minutes + t.minutes) %60;
    return retVal;
}

Time3 Time3::operator-(const Time3 & t) const {
    Time3 diff;
    int tot1, tot2;
    tot2 = hours * 60 + minutes;
    tot1 = t.hours * 60 + t.minutes;
    diff.minutes = (tot2 - tot1) & 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time3 Time3::operator*(double mult) const {
    Time3 result;
    long totalMinutes = hours * 60 * mult + minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

// void Time3::show() const{
//     std::cout << "====Time3====" << std::endl;
//     std::cout << "Hours : "<< hours << ", minutes : " << minutes << std::endl;
// }

Time3 operator*(double m ,const Time3 & t) {
    return t*m;
}

std::ostream & operator<<(std::ostream & os, const Time3 & t){
    os<< "Time3[hours : " << t.hours << ", minutes : " << t.minutes << "]" << std::endl;
    return os;
}