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

        void addMin(int m);
        void addHr(int h);
        void reset(int h=0, int m=0);

        Time operator-(const Time & t) const;
        Time operator*(double n) const;
        Time operator+(const Time & t) const;
        friend Time operator*(double m, const Time & t);   //友元函数
        // void show() const;

        //友元函数重载 show()， 注意返回的是引用
        friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif