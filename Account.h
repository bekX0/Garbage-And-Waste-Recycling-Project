#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <string>

using namespace std;

class Account{
protected:
    string name,password;
public:
    Account();
    ~Account();

    void set_name(string name);
    void set_password(string password);
    int login_account(string name, string password);
};

class User: public Account{
private:
    int wallet;
public:
    User();
    ~User();

    void set_wallet(int wallet);
    
};

class Admin: public Account{
public:
    Admin();
    ~Admin();
};

#endif _ACCOUNT_H
