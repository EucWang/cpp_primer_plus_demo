#include <iostream>

#ifndef STRING_BAD_H_
#define STRING_BAD_H_

class StringBad {
    private:
        char * str;
        int len;
        static int num_strings;
    public:
        StringBad(const char * s);
        StringBad();
        ~StringBad();

        //提供复制构造函数
        StringBad(const StringBad &);
        //提供赋值运算符
        StringBad & operator=(const StringBad &);

        friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};


#endif