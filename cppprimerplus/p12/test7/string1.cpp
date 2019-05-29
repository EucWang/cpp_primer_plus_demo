#include <iostream>
#include <cctype>
#include "string1.h"

using std::cout;
using std::cin;
using std::endl;

int String127::num_strings = 0;
 
 //默认构造
String127::String127(){
    len = 0;
    str = new char[1];
    str[0]='\0';
    num_strings++;
}      

void String127::init(const char * s) {
    len = strlen(s);
    (*this).str = new char[len +1];
    strcpy(str, s);
    num_strings++;
}

//构造函数//常规字符串的转换的构造函数
String127::String127(const char * s){
    init(s);
}   

//复制构造函数
String127::String127(const String127 & st){
    init(st.str);
}   

//析构函数
String127::~String127(){
    delete [] str;
    len = 0;
    num_strings--;
}             

//重载操作符
//赋值操作符
String127 & String127::operator=(const String127 & st){
    if( &st == this) {
        return *this;
    }
    delete [] str;
    init(st.str);
    return (*this);
}

String127 * String127::low() {
    // char * temp = new char[len + 1];
    for(int i=0; i<len; i++) {
        str[i] = tolower(str[i]);
    }
    // temp[len] = '\0';
    // String127 retVal(temp);
    // delete [] temp;
    // return retVal;
    return this;
}

String127 * String127::up() {
    // char * temp = new char[len + 1];
    for(int i=0; i<len; i++) {
        str[i] = toupper(str[i]);
    }
    // temp[len] = '\0';
    // String127 retVal(temp);
    // delete [] temp;
    return this;
}


int String127::has(const char c){
    int retVal = 0;
    for(int i=0; i<len; i++) {
        // std::cout << "index " << i << ", letter is : " << str[i] << endl;
        if( c == str[i]){
            retVal ++;
        }
    }
    return retVal;
}

//赋值操作符，
String127 & String127::operator=(const char * st){
    delete [] str;
    init(st);
    return (*this);
}

String127 operator+(const String127 & st1, const String127 & st2) {
    char * temp = new char[st1.len + st2.len + 1];
    strcpy(temp, st1.str);
    strcpy(temp + st1.len, st2.str);
    String127 retVal(temp);
    delete [] temp;
    return retVal;
}

char & String127::operator[](int i){
    return str[i];
}

const char & String127::operator[](int i) const{
    return str[i];
}

//友元
bool operator<(const String127 & st1, const String127 & st2){
    return strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String127 & st1, const String127 & st2){
    return st2 < st1;
}

bool operator==(const String127 & st, const String127 & st2){
    return (std::strcmp(st.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String127 & st){
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String127 & st){
    char temp[String127::CINLIM];
    is.get(temp, String127::CINLIM);
    if(is) {
        st = temp;
    }
    while(is && is.get() != '\n') {
        continue;
    }
    return is;
}

//静态函数
int String127::HowMany() {
    return num_strings;
}