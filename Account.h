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

    void setName(string name);
    string getName();
    void setPassword(string password);
    int loginAccount(string name, string password);
};

class User: public Account{
private:
    int wallet;
public:
    User();
    ~User();

    void setWallet(int wallet);
    int getWallet();
    
};

class Admin: public Account{
public:
    Admin();
    ~Admin();
};

#endif //_ACCOUNT_H
