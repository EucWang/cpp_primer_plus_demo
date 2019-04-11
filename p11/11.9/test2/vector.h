#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR92{
    enum Mode{RECT, POL};

    class Vector{
        private:
            double x;
            double y;
            // double mag;  //length of vector
            // double ang;  // direction of vector in degrees
            Mode mode;

            // void set_mag();
            // void set_ang();
            void set_x();
            void set_y();
            void init(double n1, double n2, Mode from);
        public:
            Vector();
            Vector(double n1, double n2, Mode from = RECT);
            void reset(double n1, double n2, Mode from = RECT);
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const;
            double angval() const;

            void polar_mode();
            void rect_mode();

            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif