#ifndef STRING_1_H_
#define STRING_1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String127{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;

        void init(const char * s);

    public:
        //构造函数
        String127(const char * s);   //常规字符串的转换的构造函数
        String127();                 //默认构造
        String127(const String127 &);   //复制构造函数
        ~String127();                //析构函数
        int length() const {return len;}  //内联函数

        //重载操作符
        String127 & operator=(const String127 &);
        String127 & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;

        String127 * low();
        String127 * up();
        int has(const char c);

        //友元
        friend bool operator<(const String127 & st, const String127 & st2);
        friend bool operator>(const String127 & st1, const String127 & st2);
        friend bool operator==(const String127 & st, const String127 & st2);

        friend String127 operator+(const String127 & st1, const String127 & st2);

        friend ostream & operator<<(ostream & os, const String127 & st);
        friend istream & operator>>(istream & is, String127 & st);

        //静态函数
        static int HowMany();
};

#endif