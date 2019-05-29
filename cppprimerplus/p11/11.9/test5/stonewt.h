#ifndef STONEWT_H_
#define STONEWT_H_

/**
 * 可以使用隐式转换将数字转换成自定义对象Stonewt
 * 那么也可以做相反的转换，将Stonewt对象转换成double值
 * 这需要使用到 转换函数 而不是构造函数
 * 
 * ⚠️注意：
 * 1. 转换函数必须是类方法
 * 2. 转换函数不能指定返回类型
 * 3. 转换函数不能有参数
 * 
 * 如何创建转换函数？
 *  operator typeName();
 * 
 * 例如， 转换为double类型的函数的原型如下
 *  operator double();
 * 
 * 
 * 
 */ 

#include <iostream>
enum STONE_TYPE95{STONE_TYPE=0,POUND_TYPE=1};

class Stonewt95 {
    private:
       
        static const int Lbs_per_stn = 14;
        // enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        enum STONE_TYPE95 type;
    public:
        
        // explicit Stonewt95(double lbs);
        //只有一个参数的类构造函数默认情况下可以隐式赋值，为了防止错误
        //⚠️注意：可以使用关键字explicit来防止隐式转换，而只允许显示转换。
        Stonewt95(double lbs);
        Stonewt95(int stn, double lbs);
        Stonewt95();
        ~Stonewt95();

        void set_type(enum STONE_TYPE95 type);

        void show_lbs() const;
        void show_stn() const;

        friend std::ostream & operator<<(std::ostream & os, Stonewt95 & s);

        Stonewt95 operator+(Stonewt95 & s2);
        Stonewt95 operator-(Stonewt95 & s2);
        Stonewt95 operator*(Stonewt95 & s2);

        //⚠️注意：应该谨慎的使用隐式转换函数，防止出现错误
        //两个转换函数
        //为了避免隐式转换导致的问题， 也可以为 转换函数增加关键字explicit,表示不能使用隐式转换，转换时必须使用强制转换
        explicit operator int() const;
        explicit operator double() const;
        // operator int() const;
        // operator double() const;
};

#endif