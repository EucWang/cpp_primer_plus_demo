#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt95::Stonewt95(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;

    pounds = lbs;
    type = STONE_TYPE;
}

Stonewt95::Stonewt95(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    type = STONE_TYPE;
}

Stonewt95::Stonewt95() {
    stone = pounds = pds_left = 0;
    type = STONE_TYPE;
}

Stonewt95::~Stonewt95(){
}

void Stonewt95::set_type(enum STONE_TYPE95 type) {
    (*this).type = type;
}

std::ostream & operator<<(std::ostream & os, Stonewt95 & s) {
    if(s.type == 0) {
        os << s.stone << " stone, " << s.pds_left << " pounds";
    }else if(s.type == 1) {
        os << s.pounds << " pounds";
    }
    return os;
}

void Stonewt95::show_lbs() const{
    cout << pounds << " pounds\n";
}

void Stonewt95::show_stn() const{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt95 Stonewt95::operator+(Stonewt95 & s2){
    return Stonewt95(pounds + s2.pounds);
}

Stonewt95 Stonewt95::operator-(Stonewt95 & s2){
    return Stonewt95(pounds - s2.pounds);
}

Stonewt95 Stonewt95::operator*(Stonewt95 & s2){
    return Stonewt95(pounds * s2.pounds);
}

Stonewt95::operator double() const{
    return pounds;
}

Stonewt95::operator int() const {
    return int(pounds + 0.5);
}