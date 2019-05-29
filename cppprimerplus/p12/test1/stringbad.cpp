#include <cstring>
#include "stringbad.h"
using std::cout;

/**
 * 不能在类声明中初始化静态成员变量，
 * 类声明描述了如何分配内存，但是并不分配内存。
 * 
 * 静态类成员可以在类声明之外进行初始化，因为静态类成员是单独存储的，不是对象的组成部分。
 * 
 * ⚠️注意： 初始化语句指出了类型，并使用了作用运算符，但是没有使用static关键字
 */ 
int StringBad::num_strings = 0;

/**
 * 类构造函数
 */ 
StringBad::StringBad(const char * s){
    (*this).len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created.\n";
}

/**
 * 类构造函数
 */ 
StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ":\"" << str << "\" default object created\n";
}

//提供复制构造函数
StringBad::StringBad(const StringBad & st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    cout << num_strings << ": \"" << str  << "\" object created\n";
}

//提供赋值运算符
StringBad & StringBad::operator=(const StringBad &st) {
    if(this == &st) {
        return *this;
    }

    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}


/**
 * 类析构函数
 */ 
StringBad::~StringBad(){
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

/**
 * 重载的类输出
 */ 
std::ostream & operator<<(std::ostream & os, const StringBad & st){
        os << st.str;
        return os;
}

