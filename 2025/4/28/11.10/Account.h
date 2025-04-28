#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    double balance;

public:
    Account(double initialBalance);
    void credit(double amount);
    bool debit(double amount);
    double getBalance() const;
};

#endif // ACCOUNT_H