#include "port.h"
#include <cstring>


// ------------ Port -----------------

Port::Port(const char * br, const char * st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);

    strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p) {
    if(this != &p) {
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);

        strcpy(style, p.style);
        bottles = p.bottles;
    }
}

Port & Port::operator=(const Port & p) {
    if ( this != &p) {
        delete [] brand;

        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);

        strcpy(style, p.style);
        bottles = p.bottles;
    }
    return *this;
}

Port & Port::operator+=(int b) {
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b) {
    bottles -= b;
    return *this;
}

void Port::show() const {
    std::cout << "Brand : " << brand << std::endl;
    std::cout << "Kind : " << style << std::endl;
    std::cout << "Bottles : " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// ------------ VintagePort -----------------

VintagePort::VintagePort()
    : Port() {
        year = 0;
        nickname = new char[1];
        nickname[0] = '\0';

}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    :Port(br, "vintage", b) {
        nickname = new char[strlen(nn) + 1];
        strcpy(nickname, nn);

        year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
    :Port(vp) {
    if(this != &vp) {
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
     if(this != &vp) {
        Port::operator=(vp);
        delete [] nickname;
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    return *this;
}

void VintagePort::show() const {
    Port::show();
    cout << "Nickname : " << nickname << endl;
    cout << "Year : " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp) {
    // operator<<(os, (Port &)vp);
    os << ((Port &)vp)
     << ", " << vp.nickname  << ", " << vp.year << endl;
    return os;
}
