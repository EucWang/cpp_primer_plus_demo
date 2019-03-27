#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

//=============AcctABC======================

class AcctABC{
    private:
        std::string fullname;
        long acctNum;
        double balance;
    protected:
        struct Formatting {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string & getFullname() const {return fullname;};
        long getAcctNum() const {return acctNum;};
        Formatting setFormat() const;
        void restore(Formatting & f) const;
    public:
        AcctABC(const std::string & s="nullbody", long an=-1, double bal=0.0);
        void deposit(double amt);
        virtual void withdraw(double amt)=0;          //  
        double getBalance() const {return balance;};
        virtual void viewAcct() const=0;
        virtual ~AcctABC() {}
};

//=============Brass======================

class Brass : public AcctABC {
    public:
        Brass(const std::string & s="Nullbody", long an=-1, double bal=0.0)
            : AcctABC(s, an, bal) {}

        virtual void withdraw(double amt);
        virtual void viewAcct() const;
        virtual ~Brass(){}
};

//=============BrassPlus======================

class BrassPlus : public AcctABC {
    private:
        double maxloan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s="Nullbody", long an=-1, double bal=0.0,
                double ml=500, double r=0.10);
        BrassPlus(const Brass & ba, double ml=500, double r=0.1);
        virtual void viewAcct() const;
        virtual void withdraw(double amt);
        void resetMax(double m){maxloan = m;};
        void resetRate(double r) {rate = r;};
        void resetOwes() {owesBank = 0; };
};

#endif