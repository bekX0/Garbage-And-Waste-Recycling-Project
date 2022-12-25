#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

// Constructors
Account::Account() {
    name = ' ';
    password = ' ';
}

Account::~Account(){}

User::User() {
    name = ' ';
    password = ' ';
    wallet = 0;
}

User::~User() {}

Admin::Admin() {
    name = ' ';
    password = ' ';
}

Admin::~Admin() {}

// login and setters
int Account::loginAccount(string name, string password) {
    if(this->name == name && this->password == password){
        return 1;
    }
    else if(this->name == name && this->password != password){
        return -1;
    }
    else if(this->name != name && this->password == password){
        return -2;
    }
    else{
        return 0;
    }
}

void Account::setName(string name){
    this->name = name;
}

string Account :: getName() {return this->name;}

void Account::setPassword(string password){
    this->password = password;
}

// wallet just for user  
void User::setWallet(int wallet) {
    this->wallet = wallet;
}

int User :: getWallet() {return this->wallet;}