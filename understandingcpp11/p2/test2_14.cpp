#include <iostream>

/**
 * C++98 中， 支持在类声明中使用等号”=“ 加初始值方式，来初始化类中的静态成员常量
 * 但是限制较多， 静态成员必须是常量，而且只能是整型或者枚举类型的常量才能初始化。
 * 
 */ 
class Init{
    public:
        Init():a(0){}
        Init(int a_) : a(a_){}
    private:
        int a;
        const static int b = 0;
        int c = 1;

        //如下3个字段，在C++11中依然不能通过编译， 不是常量，或者不是整型/枚举的常量
        // static int d = 0;   
        // static const double e = 1.3;
        // static const char * const f = "e";
};

