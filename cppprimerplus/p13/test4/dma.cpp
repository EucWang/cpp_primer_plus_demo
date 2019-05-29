#include "dma.h"


#include <iostream>
#include <cstring>


//================BaseDMA===================

/**
 * constructor
 */ 
BaseDMA::BaseDMA(const char * l, int r){
    rating = r;

    label = new char[strlen(l) + 1];
    strcpy(label, l);
}

BaseDMA::BaseDMA(const BaseDMA & rs){
    if(this == &rs) {
        return;
    }

    rating = rs.rating;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
}

BaseDMA::~BaseDMA() {
    delete [] label;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs) {
    if(this != &rs) {
        delete [] label;
        rating = rs.rating;
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs){
    os << "Label: " << rs.label << "\nRating: "<< rs.rating;
    return os;
}


//================LacksDMA===================

LacksDMA::LacksDMA(const char * c, const char * l, int r)
    : BaseDMA(l , r) {
        strncpy(color, c, 39);
        color[39] = '\0';
}

LacksDMA::LacksDMA(const char *c, const BaseDMA & rs)
    : BaseDMA(rs) {
        strncpy(color, c, 39);
        color[39] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & rs) {
    os << (const BaseDMA &)rs;  //强制类型转换，调用父类的友元方法
    os << "\nColor: " << rs.color;
    return os;
}

//================HasDMA===================

HasDMA::HasDMA(const char * s, const char * l, int r)
    :BaseDMA(l, r) {

    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & rs)
    : BaseDMA(rs) {

    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//复制构造函数   
HasDMA::HasDMA(const HasDMA & hs)
    :BaseDMA(hs) {
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

HasDMA::~HasDMA() {
    delete [] style;
}
 //赋值运算符
HasDMA & HasDMA::operator=(const HasDMA & hs) {
    if(this != &hs) {
        BaseDMA::operator=(hs);  //显示调用父类的赋值运算符
        delete [] style;

        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
    }
    return *this;
}

 std::ostream & operator<<(std::ostream & os, const HasDMA & hs) {
     os << (BaseDMA &)hs; //强制类型转换，调用父类的友元方法
     os << "\nStyle: " << hs.style ;
     return os;
 }
