#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cstring>
#include <iostream>
using namespace std;

// This class represents a bank account with an ID, a balance and a name of the owner of the account
class Account {
private:
    int m_accID;
    int m_balance;
    char* m_cusName;

public:
    // Copy constructor with deep copy
    Account(const Account& ref);
    Account(int ID, int balance, char* cname);
    ~Account();
    // This function is const because it does not modify the object or call any non const function
    int GetAccID(void) const;
    // We make this function virtual because we want to override it in the derived classes
    virtual void Deposit(int money);
    int Withdraw(int money);
    // This function is const because it does not modify the object or call any non const function
    void ShowAccInfo(void) const;
};
#endif