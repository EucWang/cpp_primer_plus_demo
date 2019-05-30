#include <iostream>
#include "test2.h"
using namespace std;

//定义单元测试，让下面的宏生效
#define UNIT_TEST

/**
 * 使用宏将所有private关键字替换成public关键字
 * 
 * 不推荐这个做法：
 * 如果使用默认的private成员访问限制， 那么这个替换不能达到目的
 * 不优雅
 */ 
#ifdef UNIT_TEST
#define private public
#endif


class Defender {
    public:
        void defence(int x, int y){cout << "defence : x : " << x << ", y : " << y << endl;}
        void trackle(int x, int y){cout << "tracke : x : " << x << ", y : " << y << endl;}
    private:
        int pos_x = 15;
        int pos_y = 0;
        int speed = 2;
        int stamina = 120;
};

class Attacker{
    public:
        void move(int x, int y) {cout << "move : x : " << x << ", y : " << y << endl;}
        void speedup(float ratio) {cout << "speedup ratio : " << ratio << endl;}
    private:
        int pos_x = 0;
        int pos_y = -30;
        int speed = 3; 
        int stamina = 100;
};

#ifdef UNIT_TEST

class Validator {
    public:
        void validate(int x, int y, Defender & d){cout << "validate : x : " << x << ", y : " << y << ", Defender" << endl;}
        void validate(int x, int y, Attacker & a){cout << "validate : x : " << x << ", y : " << y << ", Attacker " <<  endl;}
};

int testp2_21(){
    Defender d;
    Attacker a;
    a.move(15, 30);

    d.defence(15, 30);
    a.speedup(1.5f);
    d.defence(15, 30);
    Validator v;
    v.validate(7, 0, d);
    v.validate(1, -10, a);

    return 0;
}

#endif