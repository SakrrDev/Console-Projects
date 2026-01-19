#include <iostream>
#include <vector>
#include "Bank.h"
using namespace std;

int main()
{
    vector<Bank> accounts;
    int choice;

    do {
        cout << "\n--- Bank System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Show Balance\n";
        cout << "6. Show All Accounts\n";
        cout << "7. Increase Balance by Percentage\n";
        cout << "8. Add Bonus\n";
        cout << "9. Deduct Fee\n";
        cout << "10. Reset Balance\n";
        cout << "11. Double Balance\n";
        cout << "12. Halve Balance\n";
        cout << "13. Transfer All Balance\n";
        cout << "14. Rename Account\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int accNum, balance;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Account Number: "; cin >> accNum;
            cout << "Enter Initial Balance: "; cin >> balance;
            accounts.push_back(Bank(name, accNum, balance));
            cout << "Account Created!\n";
        }
        else if (choice >= 2 && choice <= 14)
        {
            int accNum;
            cout << "Enter Account Number: "; cin >> accNum;
            Bank* acc = nullptr;
            for (auto &a : accounts)
                if (a.getAccountNumber() == accNum) acc = &a;

            if (!acc) { cout << "Account not found!\n"; continue; }

            switch (choice)
            {
            case 2: {
                int amt; cout << "Amount to Deposit: "; cin >> amt;
                acc->Deposit(amt); cout << "Deposit Done!\n"; break;
            }
            case 3: {
                int amt; cout << "Amount to Withdraw: "; cin >> amt;
                cout << acc->Withdraw(amt) << endl; break;
            }
            case 4: {
                int toAccNum, amt; cout << "To Account Number: "; cin >> toAccNum;
                cout << "Amount: "; cin >> amt;
                Bank* toAcc = nullptr;
                for (auto &a : accounts) if (a.getAccountNumber() == toAccNum) toAcc = &a;
                if (!toAcc) { cout << "Target Account not found!\n"; break; }
                cout << acc->Transfer(*toAcc, amt) << endl; break;
            }
            case 5: acc->DisplayInfo(); break;
            case 6:
                for (auto &a : accounts) a.DisplaySummary(); break;
            case 7: {
                double pct; cout << "Percentage: "; cin >> pct;
                acc->AddInterest(pct); cout << "Balance increased!\n"; break;
            }
            case 8: {
                int bonus; cout << "Bonus Amount: "; cin >> bonus;
                acc->AddBonus(bonus); break;
            }
            case 9: {
                int fee; cout << "Fee Amount: "; cin >> fee;
                cout << acc->DeductFee(fee) << endl; break;
            }
            case 10: acc->ResetBalance(); cout << "Balance Reset!\n"; break;
            case 11: acc->DoubleBalance(); cout << "Balance Doubled!\n"; break;
            case 12: acc->HalveBalance(); cout << "Balance Halved!\n"; break;
            case 13: {
                int toAccNum; cout << "Transfer All to Account Number: "; cin >> toAccNum;
                Bank* toAcc = nullptr;
                for (auto &a : accounts) if (a.getAccountNumber() == toAccNum) toAcc = &a;
                if (!toAcc) { cout << "Target Account not found!\n"; break; }
                cout << acc->TransferAll(*toAcc) << endl; break;
            }
            case 14: {
                string newName; cout << "New Name: "; cin >> newName;
                acc->RenameAccount(newName); break;
            }
            }
        }
    } while (choice != 0);

    cout << "Exiting...\n";
    return 0;
}
