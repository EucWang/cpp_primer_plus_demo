#include <iostream>
#include "brass.h"

using namespace std;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, long an, double bal) {
    fullname = s;
    acctNum = an;
    balance = bal;
}

/**
 * 存钱
 */ 
void Brass::deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed; "
            << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

/**
 * 取钱
 */ 
void Brass::withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt < 0) {
        cout << "Withdrawal amount must be positive;"
            << "Withdrawal canceled.\n";
    } else if( amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawal amount of $" << amt
            << " exceeds your balance.\n"
            << "Withdrawal canceled.\n";
    }
}

double Brass::getBalance() const {
    return balance;
}

void Brass::viewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullname << endl;
    cout << "Accout Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

//=========================================

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r)
    : Brass(s, an, bal)  {
    maxloan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) 
    : Brass(ba){
    maxloan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::viewAcct() const {
    // format initialState = setFormat();
    // precis prec = cout.precision(2);

    Brass::viewAcct();
    cout << "Maximum loan: $" << maxloan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "\n";
    // restore(initialState, prec);
}

void BrassPlus::withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = getBalance();
    if(amt <= bal) {
        Brass::withdraw(amt); //调用父类的同名方法，需要指定命名空间
    }else if(amt <= bal + maxloan - owesBank){
        //超额支取范围内
        double advance = amt - bal;
        owesBank += advance *(1.0 + rate);
        cout << "Bank advance : $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        deposit(advance);  //银行向账户中存入超额支取的部分，
        Brass::withdraw(amt);  //调用父类的取钱方法
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

format setFormat(){
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}