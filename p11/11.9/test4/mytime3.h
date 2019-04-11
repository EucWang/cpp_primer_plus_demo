#ifndef _MYTIME2_H_
#define _MYTIME2_H_

#include <iostream>

class Time94{
    private:
        int hours;
        int minutes;
    public:

        Time94();
        Time94(int h, int m = 0);

        friend void addMin(Time94 & t, int m);
        friend void addHr(Time94 & t, int h);
        friend void reset(Time94 & t, int h, int m);

        friend Time94 operator-(Time94 & t0, const Time94 & t);

        friend Time94 operator+(Time94 & t0, const Time94 & t);
        friend Time94 operator*(Time94 & t0, double n);
        friend Time94 operator*(double m, const Time94 & t);   //友元函数
        // void show() const;

        //友元函数重载 show()， 注意返回的是引用
        friend std::ostream & operator<<(std::ostream & os, const Time94 & t);
};

#endif