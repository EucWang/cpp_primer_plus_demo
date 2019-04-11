#include <iostream>
#include "stock00.h"

using namespace std;


Stock128::Stock128() {
    shares = 0;
    company = new char[1];
    company[0] ='\0';
    share_val = 0.0;
    total_val = 0.0;
    // cout << "Default constructor called" << endl;
}

Stock128::~Stock128(){
    cout << "Bye," << company << "!\n";
    delete [] company;
}

// Stock128::Stock128(const std::string & co, long n, double pr) {
Stock128::Stock128(const char * co, long n, double pr) {
    // company = co;
    company = new char[strlen(co) + 1];
    strcpy(company, co);

    if(n < 0) {
        cerr << "Number of shares can't be negative;"
            << company << " shares set to 0." << endl;
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
    // cout << "Constructor using " << co << " called" << endl;
}

Stock128::Stock128(const Stock128 & st) {
    company = new char[strlen(st.company) + 1];
    strcpy(company, st.company);

    shares = st.shares;
    share_val = st.share_val;
    set_tot();
}

Stock128 & Stock128::operator=(const Stock128 & st) {
    if( this == &st) {
        return *this;
    }
    delete [] company;

    company = new char[strlen(st.company) + 1];
    strcpy(company, st.company);

    shares = st.shares;
    share_val = st.share_val;
    set_tot();
    return *this;
}

// void Stock128::acquire(const string & co, long n, double pr) {
void Stock128::acquire(const char * co, long n, double pr) {
    delete [] company;

    company = new char[strlen(co) + 1];
    strcpy(company, co);

    if(n<0){
        cout << "Number of shares can't be negative;"
            << company << " shares set to 0.\n";
        shares = 0;
    }else {
        shares = n;
    }

    share_val = pr;
    set_tot();
}

void Stock128::buy(long num, double price) {
    if(num < 0) {
        cout << "Number of shares purchased can't be negative."
            << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock128::sell(long num, double price) {
    if(num < 0) {
        cout << "Number of shares sold can't be negative."
            << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "You can't sell more than you have!"
            << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }

}

void Stock128::update(double price) {
    share_val = price;
    set_tot();
}

 /**
  * const放置在函数名称后面，表示函数的调用能保证调用对象不会被修改，调用对象和const一样，不被修改。
  */ 
// void Stock128::show() const {
//     ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
//     streamsize prec = cout.precision(3);

//     cout << "Company : " << company << "\t"
//         << "Shares : " << shares << "\t"
//         << "Share Price : $" << share_val << "\t"
//         << "Total worth : $" << total_val << endl;

//     cout.setf(orig, ios_base::floatfield);
//     cout.precision(prec);
// }

std::ostream & operator<<(std::ostream & os, const Stock128 & s) {
    os << "Company : " << s.company << "\t"
        << "Shares : " << s.shares << "\t"
        << "Share Price : $" << s.share_val << "\t"
        << "Total worth : $" << s.total_val << endl;
    return os;

}


const Stock128 & Stock128::topval(const Stock128 & s) const {
    if(s.getTotalVal() > (*this).getTotalVal()) {
        return s;
    }else {
        return (*this);
    }
}

double Stock128::getTotalVal() const {
    return (*this).total_val;
}