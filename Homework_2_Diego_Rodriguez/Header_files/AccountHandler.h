#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "Account.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
#include "BankCommon.h"

// This class aims to manage an array of different accounts
class AccountHandler
{
private:
    Account* m_accArr[MAX_ACC_NUM]; // Account array
    int m_accNum = 0; // Number of accounts
    int GetAccIdx(int id) const;

public:
    AccountHandler();
    ~AccountHandler();
    // This function is const because it does not modify the object or call any non const function
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    // This function is const because it does not modify the object or call any non const function
    void ShowAllAccInfo(void) const;
    // This function is const because it does not modify the object or call any non const function
    void ShowAccInfo(void) const;
    void DeleteAccount(void);
    void DeleteAllAccounts(void);
    void MakeSavingAccount(void);
    void MakeHighCreditAccount(void);
    // This function is const because it does not modify the object or call any non const function
    int CinIgnore(void) const;
};
#endif