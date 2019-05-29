#include "student.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student2::average() const {
    if(ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    } else {
        return 0;
    }
}

const string & Student2::name() const {
    return (string &)(*this);
}

/**
 * operator method
 */ 
double & Student2::operator[](int i) {
    return ArrayDb::operator[](i);
}

/**
 * operator method
 */ 
double Student2::operator[](int i) const {
    return ArrayDb::operator[](i);
}

ostream & Student2::arr_out(ostream & os) const {
    int i;
    int lim = ArrayDb::size();
    if(lim > 0) {
        for(i =0; i<lim; i++) {
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4) {
                os << endl;
            }
        }
        if( i%5 != 0) {
            os << endl;
        }
    }else {
        os << " empty array ";
    }
    return os;
}

/**
 * friend method
 */ 
istream & operator>>(istream & is, Student2 & stu) {
    is>>(string &) stu;
    return is;
}
/**
 * friend method
 */ 
istream & getline2(istream & is, Student2 & stu) {
    getline(is, (string &)stu);
    return is;
}
/**
 * friend method
 */ 
ostream & operator<<(ostream & os, const Student2 & stu) {
    os << "Scores for " << (const string &)stu << ":\n";
    stu.arr_out(os);
    return os;
}