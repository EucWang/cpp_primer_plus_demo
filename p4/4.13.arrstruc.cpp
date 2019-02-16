#include <iostream>

/**
 * 结构数组
 * 结构中可以包含数组
 * 也可以创建元素为结构的数组
 */ 

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

/**
 * 枚举
 * 不能对枚举应用运算
 * 如果需要将整数赋值给枚举，需要强制转换
 */ 
enum spectrum {
    red, orange, yellow, green, blue, violet, indigo, ultraviolet
};

/**
 * 可以显示的设置枚举量的值
 */ 
enum bits {
    one = 1,    two = 2,    four = 4,    eight = 8
};

/**
 * second = 100, 则 third = 101
 */ 
enum bigstep {
    first, second = 100, third
};

enum {zero, null = 0, one, numero_uno = 1};

/**
 * 公用体
 * 共用体可以同时存储 int，long ,double
 * 共用体且只能存储 int, long , double
 * 共用体一次只能存储一个值
 */ 
union one4all {
    int int_val;
    long long_val;
    double double_val;
};

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    inflatable guests[2] = 
    {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99}
    };

    cout << "The guests " << guests[0].name << " and " 
        << guests[1].name << "\nhave a combined volume of "
        << guests[0].volume + guests[1].volume << " cubic feet.\n"; 

    spectrum band = blue;
    // band++;   不能对枚举应用运算
    // spectrum band2 = 3;   //不能将整数值赋值给枚举类型
    spectrum band2 = spectrum(3);  //如果需要将整数赋值给枚举，需要强制转换

    cout << "band = " << band << endl;
    cout << "band2 = " << band2 << endl;

    one4all pail;
    pail.int_val = 5;
    cout << "set int_val : pail.int_val = " << pail.int_val << ", long_val = " << pail.long_val <<  endl;

    pail.long_val = 123424523413L;
    cout << "set long_Val : pail.long_val = " << pail.long_val << ", int_val = " << pail.int_val << endl;

    pail.double_val = 3.1415926;
    cout << "set double_val : pail.double_val = " << pail.double_val << ", int_val = " << pail.int_val << endl;

    cout<<endl;
    return 0;
}