#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt96::Stonewt96(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;

    pounds = lbs;
    type = STONE_TYPE;
}

Stonewt96::Stonewt96(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    type = STONE_TYPE;
}

Stonewt96::Stonewt96() {
    stone = pounds = pds_left = 0;
    type = STONE_TYPE;
}

Stonewt96::~Stonewt96(){

}

void Stonewt96::set_pounds(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;

    pounds = lbs;
}

void Stonewt96::set_type(enum STONE_TYPE96 type) {
    (*this).type = type;
}

std::ostream & operator<<(std::ostream & os, Stonewt96 & s) {
    if(s.type == 0) {
        os << s.stone << " stone, " << s.pds_left << " pounds";
    }else if(s.type == 1) {
        os << s.pounds << " pounds";
    }
    return os;
}

void Stonewt96::show_lbs() const{
    cout << pounds << " pounds\n";
}

void Stonewt96::show_stn() const{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt96 Stonewt96::operator+(Stonewt96 & s2){
    return Stonewt96(pounds + s2.pounds);
}

Stonewt96 Stonewt96::operator-(Stonewt96 & s2){
    return Stonewt96(pounds - s2.pounds);
}

Stonewt96 Stonewt96::operator*(Stonewt96 & s2){
    return Stonewt96(pounds * s2.pounds);
}

Stonewt96 Stonewt96::operator/(Stonewt96 & s2){
    return Stonewt96(pounds / s2.pounds);
}

bool Stonewt96::operator==(Stonewt96 & s2){
    return pounds == s2.pounds;
}


bool Stonewt96::operator>(Stonewt96 & s2){
    return (pounds > s2.pounds);
}

bool Stonewt96::operator<(Stonewt96 & s2){
     return (pounds < s2.pounds);
}


Stonewt96::operator double() const{
    return pounds;
}

Stonewt96::operator int() const {
    return int(pounds + 0.5);
}