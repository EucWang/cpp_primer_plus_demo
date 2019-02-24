#include <iostream>
#include "account.h"
#include <cstring>
using namespace std;

Account::Account(){}

Account::Account(const char * name, const char * account, const unsigned long deposit){
    strcpy(mName, name);
    (*this).mAccount = account;
    (*this).mDeposit = deposit;
}

Account::~Account(){

}


void Account::show(){
    cout << "[ACCOUNT: " << mAccount << "\t NAME: " << mName << "\t DEPOSIT: $" << mDeposit << "]" << endl; 
}

void Account::save(unsigned long money) {
    mDeposit += money;
}

bool Account::withdraw(unsigned long money) {
    if(money > mDeposit) {
        cout << "Withdraw money from your bank account fail, no much money." << endl;
        return false;
    }else {
        mDeposit -= money;
        return true;
    }
}

