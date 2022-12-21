#include <iostream>
#include <VendingMachine.h>

// Constructors
VendingMachine :: VendingMachine() {}

VendingMachine :: VendingMachine(float m, float sl) : money{money}, storage_limit{sl} {}

VendingMachine :: VendingMachine(VendingMachine &WM){
    this->money = WM.money;
    this->storage = WM.storage;
    this->storage_limit = WM.storage_limit;
}

// Getters -- Setters

float VendingMachine :: getMoney(){return this->money;}
void VendingMachine :: setMoney(float m){this->money = m;}

float VendingMachine :: getStorageInfo(){return this->money;}
void VendingMachine :: setStorageValue(float sv){this->money = sv;}

float VendingMachine :: getLimit(){return this->money;}
void VendingMachine :: setLimit(float l) {this->storage_limit=l;};

//Methods
void VendingMachine :: status(){
    cout << "Current Money in Machine: " << this->money << "$" << endl;
    cout << "Storage Status: " << this->storage << " / " << this->storage_limit << endl;
}

//================ ANORGANIC MACHINE
int VendingMachine :: inputWaste(Waste &W){
    if(this->storage + W.GetAmount() < this->storage_limit){
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
//TODO para azaltılacak 
int VendingMachine :: withdrawMoney(User &user){
    if(user.getWallet() > this->money){
        return -1;
    }
    else if(user.getWallet() < this->money){
        
        return 0;
    }
}



