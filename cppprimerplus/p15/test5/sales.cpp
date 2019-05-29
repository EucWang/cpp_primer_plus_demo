#include "sales.h"

using std::string;

/**
 * 异常继承类的构造函数
 * 嵌套类，内部类的构造函数
 */ 
Sales::BadIndex::BadIndex(int ix, const string & s)
    : std::logic_error(s), bi(ix) {
}

/**
 * 父类的构造函数
 */ 
Sales::Sales(int yy) {
    year = yy;
    for(int i=0; i<MONTHS; ++i) {
        gross[i] = 0;
    }
}

/**
 * 父类的构造函数
 */ 
Sales::Sales(int yy, const double * gr, int n) {
    year = yy;
    int lim = (n < MONTHS) ? n : MONTHS;
    int i;
    for(i=0; i<lim; i++) {
        gross[i] = gr[i];
    }
    for(; i<MONTHS; i++) {
        gross[i] = 0;
    }
}

/**
 * 重载运算符函数
 */ 
double Sales::operator[](int i) const {
    if(i<0 || i>=MONTHS) {
        throw BadIndex(i);
    }
    return gross[i];
}

/**
 * 重载运算符函数
 */ 
double & Sales::operator[](int i) {
    if(i<0 || i>=MONTHS) {
        throw BadIndex(i);
    }
    return gross[i];
}

/**
 * 异常继承类的构造函数
 * 嵌套类，内部类的构造函数
 */ 
LabeledSales::NbadIndex::NbadIndex(const string & lb, int ix, const string & s)
    : Sales::BadIndex(ix, s){
    lbl = lb;
}

/**
 * 子类的构造函数
 */ 
LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n)
    : Sales(yy, gr, n){
    label = lb;
}

/**
 * 重载运算符函数
 */ 
double LabeledSales::operator[](int i) const {
    if(i <0 || i >= MONTHS){
        throw NbadIndex(getLabel(), i);
    }
    return Sales::operator[](i);
}

/**
 * 重载运算符函数
 */ 
double & LabeledSales::operator[](int i) {
    if(i <0 || i >= MONTHS){
        throw NbadIndex(getLabel(), i);
    }
    return Sales::operator[](i);
}
