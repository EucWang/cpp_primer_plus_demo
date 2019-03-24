#ifndef STRING_1_H_
#define STRING_1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;

        void init(const char * s);

    public:
        //构造函数
        String(const char * s);   //常规字符串的转换的构造函数
        String();                 //默认构造
        String(const String &);   //复制构造函数
        ~String();                //析构函数
        int length() const {return len;}  //内联函数

        //重载操作符
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;

        String * low();
        String * up();
        int has(const char c);

        //友元
        friend bool operator<(const String & st, const String & st2);
        friend bool operator>(const String & st1, const String & st2);
        friend bool operator==(const String & st, const String & st2);

        friend String operator+(const String & st1, const String & st2);

        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, String & st);

        //静态函数
        static int HowMany();
};

#endif