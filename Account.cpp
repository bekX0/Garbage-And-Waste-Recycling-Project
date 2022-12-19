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
int Account::login_account(string name, string password) {
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

void Account::set_name(string name){
    this->name = name;
}

void Account::set_password(string password){
    this->password = password;
}

// wallet sadece usera ozel 
void User::set_wallet(int wallet) {
    this->wallet = wallet;
}



