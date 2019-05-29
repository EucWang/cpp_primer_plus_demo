#include "tv3.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//---------------- Tv --------------------

/**
 * public method
 */ 
bool Tv3::volup(){
    if(volume < MaxVal) {
        volume++;
        return true;
    }else {return false;}
}
/**
 * public method
 */ 
bool Tv3::voldown(){
    if(volume > MinVal) {
        volume--;
        return true;
    }else {return false;}
}
/**
 * public method
 */ 
void Tv3::chanup() {
    if(channel < maxchannel) {
        channel++;
    } else{channel =1;}
}
/**
 * public method
 */ 
void Tv3::chandown() {
    if(channel > 1){
        channel--;
    }else {channel = maxchannel;}
}
/**
 * public method
 */ 
void Tv3::settings() const {
    cout << "Tv3 is " <<
        (state == OFF?"OFF":"ON") << endl;
    
    if(state == ON) {
        cout << "Volume setting = " << volume <<endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna ? "antenna" : "cable")
            << endl;
        cout << "Input = " << (input==TV?"TV":"DVD")<<endl;
    }
}
