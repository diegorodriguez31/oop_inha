#ifndef HIGH_CREDIT_ACCOUNT_H
#define HIGH_CREDIT_ACCOUNT_H
#include "SavingAccount.h"

// This class is a type of saving account with a special credit rate
class HighCreditAccount : public SavingAccount {
private:
    int m_SpecialRate;
public:
    // We add the special credit rate parameter to the constructor
    HighCreditAccount(int ID, int balance, char* cname, int rate, int special);
    // We make the deposit function virtual so that it can be overriden in the derived class
    virtual void Deposit(int money);
};
#endif