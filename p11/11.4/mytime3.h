#ifndef _MYTIME2_H_
#define _MYTIME2_H_

#include <iostream>

class Time3{
    private:
        int hours;
        int minutes;
    public:
        Time3();
        Time3(int h, int m = 0);

        void addMin(int m);
        void addHr(int h);
        void reset(int h=0, int m=0);

        Time3 operator-(const Time3 & t) const;
        Time3 operator*(double n) const;
        Time3 operator+(const Time3 & t) const;
        friend Time3 operator*(double m, const Time3 & t);   //友元函数
        // void show() const;

        //友元函数重载 show()， 注意返回的是引用
        friend std::ostream & operator<<(std::ostream & os, const Time3 & t);
};

#endif