#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

// Constructors
Account::Account() {
    name = ' ';
    password = ' ';
}

User::User() {
    name = ' ';
    password = ' ';
    wallet = 0;
}

Admin::Admin() {
    name = ' ';
    password = ' ';
}

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

// wallet sadece usera ozel 
void User::setWallet(int wallet) {
    this->wallet = wallet;
}

int User :: getWallet() {return this->wallet;}



