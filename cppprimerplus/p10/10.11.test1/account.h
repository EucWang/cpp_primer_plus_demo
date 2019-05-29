#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {
    private:
        static const int LEN = 40;
        char mName[LEN];
        std::string mAccount;
        unsigned long mDeposit;
    public:
        Account();
        Account(const char * name, const char * account, const unsigned long deposit=0);
        ~Account();

        void show();
        void save(unsigned long money);
        bool withdraw(unsigned long money);
};

#endif