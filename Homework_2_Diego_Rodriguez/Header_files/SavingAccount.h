#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "Account.h"

// This class is a type of Account with interest rate as a new parameter in pourcentage
class SavingAccount : public Account {
private:
    int m_InterestRate; // In %
public:
    // We add the rate parameter to the constructor
    SavingAccount(int ID, int balance, char* cname, int rate);
    // We make the deposit function virtual so that it can be overriden in the derived class
    virtual void Deposit(int money);
};

#endif