#ifndef _MYTIME2_H_
#define _MYTIME2_H_

#include <iostream>

class Time{
    private:
        int hours;
        int minutes;
    public:

        Time();
        Time(int h, int m = 0);

        friend void addMin(Time & t, int m);
        friend void addHr(Time & t, int h);
        friend void reset(Time & t, int h, int m);

        friend Time operator-(Time & t0, const Time & t);

        friend Time operator+(Time & t0, const Time & t);
        friend Time operator*(Time & t0, double n);
        friend Time operator*(double m, const Time & t);   //友元函数
        // void show() const;

        //友元函数重载 show()， 注意返回的是引用
        friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif