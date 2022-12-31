#include <iostream>
#include "../Header_files/AccountHandler.h"
#include "../Header_files/BankCommon.h"
using namespace std;

// Main program
int main(void) {
    AccountHandler manager; // This is the object that will handle the accounts
    int choice;
    bool run = true;

    while(run) {
        manager.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid: you need to enter a number..." << endl;
        }
        cout << endl << endl << endl;

        // Thanks to the BankCommon file, we can use the enum to make the code more readable
        switch(BANK(choice)){
            case BANK::MAKE:
                manager.MakeAccount();
                break;
            case BANK::DEPOSIT:
                manager.DepositMoney();
                break;
            case BANK::WITHDRAW:
                manager.WithdrawMoney();
                break;
            case BANK::INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case BANK::INQUIREONE:
                manager.ShowAccInfo();
                break;
            case BANK::DELETE:
                manager.DeleteAccount();
                break;
            case BANK::DELETEALL:
                manager.DeleteAllAccounts();
                break;
            case BANK::EXIT:
                manager.~AccountHandler();
                return 0;
            default:
                cout << "Illegal selection..." << endl;
                choice = 0;
        }
    }
    return 0;
}