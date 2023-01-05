#include <iostream>


#include "VendingMachine.h"
// #include "Waste.h"
// #include "Account.h"
class Waste;
class User;

using namespace std;


// Constructors
/* VENDING MACHINE */
VendingMachine :: VendingMachine() {}

VendingMachine :: VendingMachine(float m, int sl, string cn) : money{m}, storage_limit{sl}, city{cn} {}



VendingMachine :: VendingMachine(const VendingMachine &WM){
    this->money = WM.money;
    this->storage = WM.storage;
    this->storage_limit = WM.storage_limit;
    this->city = WM.city;
}

/* ORGANIC VENDING MACHINE*/
OrganicVendingMachine :: OrganicVendingMachine() {}
OrganicVendingMachine :: OrganicVendingMachine(float m, float sl) : storage_limit{sl} {this->money = m;}
OrganicVendingMachine :: OrganicVendingMachine(float m, float sl, string city) : storage_limit{sl} {this->money = m; this->city =city;}

// Destructors
VendingMachine :: ~VendingMachine() {}
OrganicVendingMachine :: ~OrganicVendingMachine() {}

// Getters -- Setters

float VendingMachine :: getMoney(){return this->money;}
void VendingMachine :: setMoney(float m){this->money = m;}

float VendingMachine :: getStorageInfo(){return this->money;}
void VendingMachine :: setStorageValue(float sv){this->money = sv;}

int VendingMachine :: getLimit(){return this->storage_limit;}
void VendingMachine :: setLimit(float l) {this->storage_limit=l;};

string VendingMachine :: getCity(){return this->city;}
void VendingMachine :: setCity(string city) {this->city = city;}

//Methods
void VendingMachine :: status(){
    cout << "Current Money in Machine: " << this->money << "$" << endl;
    cout << "Storage Status: " << this->storage << " / " << this->storage_limit << endl;
}

//================ ANORGANIC MACHINE
int VendingMachine :: inputWaste(Waste &W){
    if(this->storage + W.GetAmount() < this->storage_limit){
        // this->storage += W.GetAmount();
        // user.setWallet(user.getWallet() + W.GetPrice()*W.GetAmount());
        return 0;
    }
    else if(this->storage + W.GetAmount() > this->storage_limit){
        return -1;
    }
} 

//================= ORGANIC MACHINE

int OrganicVendingMachine :: inputWaste(Waste &W){
   if(this->storage + W.GetWeight() < this->storage_limit){
        return 0;
    } 
    else if(this->storage + W.GetWeight() > this->storage_limit){
        return -1;
    }
}

//================= WITHDRAW MONEY 
//? güncelleme önerisi: istediği kadar bakiye çekmek isterse? (negatif sayı çekmek isterse)
int VendingMachine :: withdrawMoney(User &user){
    if(user.getWallet() > this->money){
        return -1;
    }
    else if(user.getWallet() < this->money){
        this->money - user.getWallet();
        user.setWallet(0);
        return 0;
    }
}



