#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;

    pounds = lbs;
    type = STONE_TYPE;
}

Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    type = STONE_TYPE;
}

Stonewt::Stonewt() { 
    stone = pounds = pds_left = 0;
    type = STONE_TYPE;
}

Stonewt::~Stonewt(){
}

void Stonewt::set_type(enum STONE_TYPE type) {
    (*this).type = type;
}

std::ostream & operator<<(std::ostream & os, Stonewt & s) {
    if(s.type == 0) {
        os << s.stone << " stone, " << s.pds_left << " pounds";
    }else if(s.type == 1) {
        os << s.pounds << " pounds";
    }
    return os;
}

void Stonewt::show_lbs() const{
    cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt Stonewt::operator+(Stonewt & s2){
    return Stonewt(pounds + s2.pounds);
}

Stonewt Stonewt::operator-(Stonewt & s2){
    return Stonewt(pounds - s2.pounds);
}

Stonewt Stonewt::operator*(Stonewt & s2){
    return Stonewt(pounds * s2.pounds);
}

Stonewt::operator double() const{
    return pounds;
}

Stonewt::operator int() const {
    return int(pounds + 0.5);
}