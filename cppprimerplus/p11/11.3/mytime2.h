#ifndef _MYTIME2_H_
#define _MYTIME2_H_

class Time2{
    private:
        int hours;
        int minutes;
    public:
        Time2();
        Time2(int h, int m = 0);

        void addMin(int m);
        void addHr(int h);
        void reset(int h=0, int m=0);

        Time2 operator-(const Time2 & t) const;
        Time2 operator*(double n) const;
        Time2 operator+(const Time2 & t) const;
        void show() const;
};

#endif