#include <iostream>
#include "string1.h"

using std::cout;
using std::cin;
using std::endl;

int String::num_strings = 0;
 
 //默认构造
String::String(){
    len = 0;
    str = new char[1];
    str[0]='\0';
    num_strings++;
}      

void String::init(const char * s) {
    len = strlen(s);
    (*this).str = new char[len +1];
    strcpy(str, s);
    num_strings++;
}

//构造函数//常规字符串的转换的构造函数
String::String(const char * s){
    init(s);
}   

//复制构造函数
String::String(const String & st){
    init(st.str);
}   

//析构函数
String::~String(){
    delete [] str;
    len = 0;
    num_strings--;
}             

//重载操作符
//赋值操作符
String & String::operator=(const String & st){
    if( &st == this) {
        return *this;
    }
    delete [] str;
    init(st.str);
    return (*this);
}

//赋值操作符，
String & String::operator=(const char * st){
    delete [] str;
    init(st);
    return (*this);
}

char & String::operator[](int i){
    return str[i];
}

const char & String::operator[](int i) const{
    return str[i];
}

//友元
bool operator<(const String & st1, const String & st2){
    return strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String & st1, const String & st2){
    return st2 < st1;
}

bool operator==(const String & st, const String & st2){
    return (std::strcmp(st.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st){
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st){
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is) {
        st = temp;
    }
    while(is && is.get() != '\n') {
        continue;
    }
    return is;
}

//静态函数
int String::HowMany() {
    return num_strings;
}