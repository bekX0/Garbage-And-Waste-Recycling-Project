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

// User setters
void User::set_name(string name){
    this->name = name;
}

void User::set_password(string password){
    this->password = password;
}

void User::set_wallet(int wallet) {
    this->wallet = wallet;
}

int User::login_account(string name, string password) {
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

// Admin setters
void Admin::set_name(string name) {
    this->name = name;
}

void Admin::set_password(string password) {
    this->password = password;
}

int Admin::login_account(string name, string password) {
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