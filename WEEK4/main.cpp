#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
    int choice;

    while(1) {
        ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid: you need to enter a number..." << endl;
        }
        cout << endl << endl << endl << endl << endl;

        switch(bank(choice)){
            case bank::MAKE:
                MakeAccount();
                break;
            case bank::DEPOSIT:
                DepositMoney();
                break;
            case bank::WITHDRAW:
                WithdrawMoney();
                break;
            case bank::INQUIRE:
                ShowAllAccInfo();
                break;
            case bank::INQUIREONE:
                ShowAccInfo();
                break;
            case bank::DELETE:
                DeleteAccount();
                break;
            case bank::DELETEALL:
                DeleteAllAccounts();
                break;
            case bank::EXIT:
                return 0;
            default:
                cout << "Wrong number..." << endl;
                choice = 0;
        }
    }
    return 0;
}