#include "acctabc.h"


//===============AcctABC 基类======================

AcctABC::Formatting AcctABC::setFormat() const{
    Formatting f;
    f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = std::cout.precision(2);
    return f;
}

void AcctABC::restore(Formatting & f) const {
    std::cout.setf(f.flag, std::ios_base::floatfield);
    std::cout.precision(f.pr);
}

/**
 * constructor
 */ 
AcctABC::AcctABC(const std::string & s, long an, double bal){
    fullname = s;
    acctNum = an;
    balance = bal;
}

/**
 * 存钱
 */ 
void AcctABC::deposit(double amt) {
    if(amt < 0) {
        std::cout << "deposit money must a positive value, \ndeposit is cancelled." << std::endl;
    } else {
        balance += amt;
    }
}

/**
 * 虽然是一个纯虚函数，但是依然可以给出实现
 */ 
void AcctABC::withdraw(double amt) {
    balance -= amt;
}
      

//===============Brass 派生类1 普通账户======================

/**
 * 取钱
 */ 
void Brass::withdraw(double amt){
    if(amt < 0) {
        std::cout << "Withdrawal amount must be positive;"
            << "Withdrawal canceled." << std::endl;
    } else if(amt <= getBalance()) {
        AcctABC::withdraw(amt);
    } else {
        std::cout<< "Withdrawal amount of $" << amt
            << " exceeds your balance.\n"
            << "Withdrawal canceled.\n";
    }
}

/**
 * 显示账户信息
 */ 
void Brass::viewAcct() const{
    AcctABC::Formatting f = setFormat();
    std::cout << std::endl;
    std::cout << "Brass Client: "<< getFullname() << std::endl;
    std::cout << "Account Number: " << getAcctNum() << std::endl;
    std::cout << "Balance: $" << getBalance() << std::endl;

    restore(f);
}

//===============BrassPlus 派生类2 可以透支的账户======================

/**
 * constructor
 */ 
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
        : AcctABC(s, an, bal), maxloan(ml), rate(r), owesBank(0.0){}

/**
 * constructor, call base class's copy constructor
 */ 
BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
        : AcctABC(ba), maxloan(ml), rate(r) , owesBank(0.0){}


/**
 * 显示账户信息
 */ 
void BrassPlus::viewAcct() const{
    AcctABC::Formatting f = setFormat();

    std::cout << std::endl;
    std::cout << "BrassPlus Client: "<< getFullname() << std::endl;
    std::cout << "Account Number: " << getAcctNum() << std::endl;
    std::cout << "Balance: $" << getBalance() << std::endl;
    std::cout << "Maximum loan: $" << maxloan << std::endl;
    std::cout << "Owed to bank: $" << owesBank << std::endl;

    std::cout.precision(3);
    std::cout << "Loan Rate: " << 10 * rate << "%\n";

    restore(f);
}

/**
 * 取钱，可以透支
 */ 
void BrassPlus::withdraw(double amt){
    AcctABC::Formatting f = setFormat();

    double bal = getBalance();
    if(amt <= bal) {
        AcctABC::withdraw(amt); 
    } else if(amt <= bal + maxloan - owesBank) {  //位于可透支范围类
        double advance = amt - bal;  //透支的部分
        owesBank += advance * (1.0 + rate);  
        std::cout << "Bank advance: $" << advance << std::endl;
        std::cout << "Finance charge: $" << advance * rate << std::endl;

        deposit(advance);  //将透支的金额打入客户账户中
        AcctABC::withdraw(amt);  //然后再正常取钱
    } else {
        std::cout << "Credit limit exceeded. Transaction cancelled.\n";
    }

    restore(f);
}
