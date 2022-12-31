#include "../Header_files/Account.h"

// This is the copy constructor of the Account class with a deep copy. The objective is written
// in the report. We use the strcpy function to copy the string of the name of the customer.
// To define the length of the string, we use the strlen function that returns the length of the
// original string and then we add + 1 for the escape character.
Account::Account(const Account& ref): m_accID{ref.m_accID}, m_balance{ref.m_balance} {
    int len = strlen(ref.m_cusName) + 1;
    m_cusName = new char[len];
    strcpy(m_cusName, ref.m_cusName);
};

// To initialize the name, we use the strcpy function to copy the string of the name of the customer.
Account::Account(int ID, int balance, char* cname) : m_accID{ID}, m_balance{balance} {
        int len = strlen(cname) + 1;
        m_cusName = new char[len];
        strcpy(m_cusName, cname);
    }

// We just need to delete the name of the customer because it is the only parameter using dynamic memory
Account::~Account() {
        delete[] m_cusName;
    } 

int Account::GetAccID(void) const {
    return m_accID;
}

// I decided that we can't deposit a negative amount of money that would act like a withdrawal
void Account::Deposit(int money) {
    if (money > 0) {
        m_balance += money;
    } else {
        cout << "Please insert a positive value" << endl;
    }
}

// We can't withdraw more money than we have in our account. Same than the deposit,
// we can't withdraw a negative amount of money to act like a deposit
int Account::Withdraw(int money) {
    if ((m_balance <= 0) || (money > m_balance) || (money < 0)) {
        return -1;
    }
    m_balance -= money;
    return money;
}

void Account::ShowAccInfo(void) const {
    cout << "Account ID: " << m_accID << endl;
    cout << "Name: " << m_cusName << endl;
    cout << "Balance: " << m_balance << endl << endl;
}