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

float getLimit();
void setLimit(float l);