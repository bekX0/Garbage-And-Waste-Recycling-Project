#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


#include "Account.h"
// #include "VendingMachine.h"
// #include "Waste.h"

using namespace std;

// Constructors
Account::Account() {
    name = ' ';
    password = ' ';
}
Account :: Account(const Account &acc){
    this->name = acc.name;
    this->password = acc.password;
}

Account::~Account(){}

User::User() {
    name = ' ';
    password = ' ';
    wallet = 0;
}

User::User(string name, string password) {this->name = name; this->password =password; this->wallet = 0;} 

User::~User() {}

Admin::Admin() {
    name = ' ';
    password = ' ';
}

Admin::Admin(string name, string password) {this->name = name; this->password =password;}

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
    this->wallet += wallet;
}

int User :: getWallet() {return this->wallet;}

string User :: getPassword() {return this->password;}

void User :: saveInfo(User &user){
    file.open("UserDatabase.txt",ios::out);

    file << user.getName() << setw(10) << user.getPassword() << setw(10) << user.getWallet() << endl;

    file.close();
}

void Admin :: getInfo(){
    string myText;

    file.open("UserDatabase.txt",ios::in);

    cout << "Username " << setw(10) << "Password " << setw(10) << "Budget " << endl;

    while(getline (file, myText)){
		cout << myText << endl;
	}

    file.close();
}

int Admin::loginAdmin(string name, string password) {
    if(this->name == name && this->password == password){
        return 1;
    }
    else{
        return 0;
    }
}