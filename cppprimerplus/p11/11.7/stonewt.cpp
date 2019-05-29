#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt7::Stonewt7(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;
    pounds = lbs;
}

Stonewt7::Stonewt7(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt7::Stonewt7(){
    stone = pounds = pds_left = 0;
}

Stonewt7::~Stonewt7(){
}

void Stonewt7::show_lbs() const{
    cout << pounds << " pounds\n";
}

void Stonewt7::show_stn() const{
    cout << stone << " stone, " << pds_left << " pounds\n";
}


Stonewt7::operator double() const{
    return pounds;
}

Stonewt7::operator int() const {
    return int(pounds + 0.5);
}