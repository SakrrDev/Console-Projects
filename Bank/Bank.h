#pragma once
#include <iostream>
using namespace std;

class Bank
{
private:
    string _accountName;
    int _accountNumber;
    int _balance;

public:

    Bank() : _accountName(""), _accountNumber(0), _balance(0) {}
    Bank(string name, int accountNumber, int balance)
        : _accountName(name), _accountNumber(accountNumber), _balance(balance) {} 
    
    string getName() const { return _accountName; }
    int getAccountNumber() const { return _accountNumber; }
    int getBalance() const { return _balance; }

    void setInfo(string name, int accountNumber, int balance)
    {
        _accountName = name;
        _accountNumber = accountNumber;
        _balance = balance;
    }

    void setName(const string &newname) { _accountName = newname; }

    void Deposit(int amount) { _balance += amount; }

    string Withdraw(int amount)
    {
        if (_balance < amount) return "Insufficient balance";
        _balance -= amount;
        return "Done";
    }

    string Transfer(Bank &toAccount, int amount)
    {
        if (_balance < amount) return "Insufficient balance";
        _balance -= amount;
        toAccount.Deposit(amount);
        return "Done";
    }

    int ShowBalance() const { return _balance; }

    void DisplayInfo() const
    {
        cout << "Account Number: " << _accountNumber << endl;
        cout << "Account Name: " << _accountName << endl;
        cout << "Balance: " << _balance << endl;
    }

    // 12 Additional Functions

    bool IsBalanceZero() const { return _balance == 0; }

    bool IsBalancePositive() const { return _balance > 0; }

    void AddBonus(int bonus) { if (bonus > 0) _balance += bonus; }

    string DeductFee(int fee)
    {
        if (_balance < fee) return "Insufficient balance";
        _balance -= fee;
        return "Fee Deducted";
    }

    void ResetBalance() { _balance = 0; }

    void RenameAccount(const string &newName) { _accountName = newName; }

    void DoubleBalance() { _balance *= 2; }

    void HalveBalance() { _balance /= 2; }

    string TransferAll(Bank &toAccount)
    {
        if (_balance == 0) return "No balance to transfer";
        toAccount.Deposit(_balance);
        _balance = 0;
        return "All balance transferred";
    }

    int CompareBalance(const Bank &other) const
    {
        if (_balance > other._balance) return 1;
        else if (_balance < other._balance) return -1;
        else return 0;
    }

    void AddInterest(double percent)
    {
        if (percent > 0) _balance += static_cast<int>(_balance * percent / 100.0);
    }

    void DisplaySummary() const
    {
        cout << "Account: " << _accountNumber
             << " | Name: " << _accountName
             << " | Balance: " << _balance << endl;
    }
};
