#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
    double balance;

public:
    Account(double initialBalance);
    virtual ~Account() = default;
    virtual void credit(double);
    virtual bool debit(double);
    double getBalance() const;
};

#endif // ACCOUNT_H