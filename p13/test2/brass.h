#ifndef BRASS_H_
#define BRASS_H_
#include <string>
using namespace std;

class Brass{
    private:
        string fullname;
        long acctNum;
        double balance;
    public:
        Brass(const string & s="Nullbody", long an=-1, double bal = 0.0);
        void deposit(double amt);
        virtual void withdraw(double amt);
        double getBalance() const;
        virtual void viewAcct() const;
        virtual ~Brass(){}
};

class BrassPlus : public Brass {
    private:
        double maxloan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const string & s="NullBody", long an=-1, double bal=0.0, double ml=500, double r=0.11125);
        BrassPlus (const Brass & ba, double ml=500, double r = 0.11125);
        virtual void viewAcct() const;
        virtual void withdraw(double amt);
        void resetMax(double m){maxloan = m;};
        void resetRate(double r){rate =r;};
        void resetOwes(){owesBank = 0;};
};

#endif