#include "dma.h"
#include <iostream>
#include <cstring>

//================DmaABC===================

DmaABC::DmaABC(const char * l, int r){
    rating = r;

    label = new char[strlen(l) + 1];
    strcpy(label, l);
}

DmaABC::DmaABC(const DmaABC & rs){
    if(this == &rs) {
        return;
    }

    rating = rs.rating;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
}

DmaABC::~DmaABC() {
    delete [] label;
}

DmaABC & DmaABC::operator=(const DmaABC & rs) {
    if(this != &rs) {
        delete [] label;
        rating = rs.rating;
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
    }
    return *this;
}

// std::ostream & operator<<(std::ostream & os, const DmaABC & rs){
//     os << "Label: " << rs.label << "\nRating: "<< rs.rating;
//     return os;
// }

void DmaABC::view() const {
    std::cout << "===Label: " << label <<", Rating: " <<rating << std::endl;
}

//================BaseDMA7===================
 
void BaseDMA7::view() const {
    std::cout << "BaseDMA7: ==>";
    DmaABC::view();
}

//================LacksDMA7===================

LacksDMA7::LacksDMA7(const char * c, const char * l, int r)
    : DmaABC(l , r) {
        strncpy(color, c, 39);
        color[39] = '\0';
}

LacksDMA7::LacksDMA7(const char *c, const DmaABC & rs)
    : DmaABC(rs) {
        strncpy(color, c, 39);
        color[39] = '\0';
}

// std::ostream & operator<<(std::ostream & os, const LacksDMA7 & rs) {
//     os << (const BaseDMA7 &)rs;  //强制类型转换，调用父类的友元方法
//     os << "\nColor: " << rs.color;
//     return os;
// }

void LacksDMA7::view() const {
    std::cout << "LacksDMA7: ==>==>";
    DmaABC::view();
}
//================HasDMA7===================

HasDMA7::HasDMA7(const char * s, const char * l, int r)
    :DmaABC(l, r) {

    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

HasDMA7::HasDMA7(const char * s, const DmaABC & rs)
    : DmaABC(rs) {

    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//复制构造函数   
HasDMA7::HasDMA7(const HasDMA7 & hs)
    :DmaABC(hs) {
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

HasDMA7::~HasDMA7() {
    delete [] style;
}
 //赋值运算符
HasDMA7 & HasDMA7::operator=(const HasDMA7 & hs) {
    if(this != &hs) {
        DmaABC::operator=(hs);  //显示调用父类的赋值运算符
        delete [] style;

        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
    }
    return *this;
}

void HasDMA7::view() const {
    std::cout << "HasDMA7: ==>==>==>";
    DmaABC::view();
}

//  std::ostream & operator<<(std::ostream & os, const HasDMA7 & hs) {
//      os << (BaseDMA7 &)hs; //强制类型转换，调用父类的友元方法
//      os << "\nStyle: " << hs.style ;
//      return os;
//  }