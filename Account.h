#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <fstream>

using namespace std;

class Account
{
protected:
    fstream file;
    string name, password;

public:
    // Constructor
    Account();
    Account(const Account &acc);
    // Destructor
    virtual ~Account();

    // Getters -- Setters
    virtual void setName(string name);
    virtual string getName();
    virtual void setPassword(string password);

    // Methods
    virtual int loginAccount(string name, string password);
};

class User : public Account
{
private:
    int wallet;

public:
    // Constructor
    User(); // No-args Const.
    User(string name, string password); // Two args Const.

    // Destructor
    virtual ~User();


    // Getters -- Setters
    virtual void setWallet(int wallet);
    virtual int getWallet();
    virtual string getPassword();
    virtual void saveInfo(User &a);
};

class Admin : public Account
{
public:
    // Constructor
     Admin();

    // Destructor
    virtual ~Admin();

    // Methods
    virtual void getInfo();
};

#endif //_ACCOUNT_H
