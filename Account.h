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

    // Destructor
    ~Account();

    // Getters -- Setters
    void setName(string name);
    string getName();
    void setPassword(string password);

    // Methods
    int loginAccount(string name, string password);
};

class User : public Account
{
private:
    int wallet;

public:
    // Constructor
    User();

    // Destructor
    ~User();

    // Getters -- Setters
    void setWallet(int wallet);
    int getWallet();
    string getPassword();
    void saveInfo(User &a);
};

class Admin : public Account
{
public:
    // Constructor
    Admin();

    // Destructor
    ~Admin();

    // Methods
    void getInfo();
};

#endif //_ACCOUNT_H
