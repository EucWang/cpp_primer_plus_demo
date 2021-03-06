#include "student.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;
using std::cout;

double Student::average() const {
    if(scores.size() > 0) {
        return scores.sum() / scores.size();
    } else {
        return 0;
    }
}

const std::string & Student::getName() const {
    return name;
}


double & Student::operator[](int i) {
    if(i < scores.size()) {
        return scores[i];
    } else {
        cout << "Illegal Argument, index i outof bound.\n";
        return scores[0];
    }
}

double Student::operator[](int i) const {
    if(i < scores.size()) {
        return scores[i];
    } else {
        cout << "Illegal Argument, index i outof bound.\n";
        return scores[0];
    }
}

/**
 * private method
 */ 
std::ostream & Student::arr_out(std::ostream & os) const{
    int i;
    int lim = scores.size();
    if(lim > 0) {
        for(i =0; i<lim; i++) {
            os << scores[i] << " ";
            if( i % 5 == 4) {
                os << endl;
            }
        } 
        if(i % 5 != 0) {
            os << endl;
        }
    } else {
        os << " empty array";
    }
    return os;
}

std::istream & operator>>(std::istream & is, Student & stu) {
    is >> stu.name;
    return is;
}

std::istream & getline3(std::istream & is, Student & stu) {
    getline(is, stu.name);
    return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu) {
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
