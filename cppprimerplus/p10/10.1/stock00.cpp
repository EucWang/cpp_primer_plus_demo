#include <iostream>
#include "stock00.h"

using namespace std;


Stock::Stock() {
    shares = 0;
    company = "";
    share_val = 0.0;
    total_val = 0.0;
    // cout << "Default constructor called" << endl;
}

Stock::~Stock(){
    cout << "Bye," << company << "!\n";
}

Stock::Stock(const std::string & co, long n, double pr) {
    company = co;
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

void Stock::acquire(const string & co, long n, double pr) {
    company = co;
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

void Stock::buy(long num, double price) {
    if(num < 0) {
        cout << "Number of shares purchased can't be negative."
            << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
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

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

 /**
  * const放置在函数名称后面，表示函数的调用能保证调用对象不会被修改，调用对象和const一样，不被修改。
  */ 
void Stock::show() const {
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout << "Company : " << company << "\t"
        << "Shares : " << shares << "\t"
        << "Share Price : $" << share_val << "\t"
        << "Total worth : $" << total_val << endl;

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const {
    if(s.getTotalVal() > (*this).getTotalVal()) {
        return s;
    }else {
        return (*this);
    }
}

double Stock::getTotalVal() const {
    return (*this).total_val;
}