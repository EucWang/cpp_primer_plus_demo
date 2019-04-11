#ifndef _MYTIME1_H_
#define _MYTIME1_H_

class Time1{
    private:
        int hours;
        int minutes;
    public:
        Time1();
        Time1(int h, int m = 0);
        void addMin(int m);
        void addHr(int h);
        void reset(int h=0, int m=0);
        Time1 operator+(const Time1 & t) const;
        void show() const;
};

#endif