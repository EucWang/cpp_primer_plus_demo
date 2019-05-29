#include "vector.h"
#include <cmath>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR91 {

    const double RAD_TO_DEG = 45.0/atan(1.0);

    //private
    void Vector::set_mag(){ mag = sqrt(x*x + y*y); }

    void Vector::set_ang(){
        if(x == 0.0 && y == 0.0) { ang = 0.0;
        } else { ang = atan2(y, x); }
    }

    void Vector::set_x() { x = mag * cos(ang); }
    void Vector::set_y() { y = mag * sin(ang); }
    void Vector::init(double n1, double n2, Mode from) {
        mode = from;
        if (mode  == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if (mode == POL) {
            mag = n1;
            ang = n2/RAD_TO_DEG;
            set_x();
            set_y();
        } else {
            cout << "Incorrenct 3rd argument to Vector() --";
            cout << "Vector set to 0" << endl;
            x = y = ang = mag = 0;
            mode = RECT;
        }
    }

    //public
    Vector::Vector(){
        x = 0;
        y = 0;
        mag = 0;
        ang = 0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode from) {
        init(n1, n2, from);
    }

    void Vector::reset(double n1, double n2, Mode from) {
        init(n1, n2, from);
    }

    Vector::~Vector(){}

    void Vector::polar_mode(){ mode = POL; }

    void Vector::rect_mode(){ mode = RECT; }

    Vector Vector::operator+(const Vector & b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }
    
    Vector Vector::operator*(double n) const {
        return Vector(n*x, n*y);
    }

    //friend
    Vector operator*(double n, const Vector & a) {
        return a*n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v) {
        if ( v.mode == RECT) {
            os << "(x, y) = (" << v.xval() << ", " << v.yval() << ")" <<endl;
        } else if (v.mode == POL) {
            os << "(mag, ang) = (" << v.magval() << ", " << v.angval() * RAD_TO_DEG << ")" << endl;
        } else {
            os << "Vector object mode is invalid!!" << endl;
        }
        return os;
    }

}