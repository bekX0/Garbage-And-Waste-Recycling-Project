#ifndef _VENDINGMACHINE_H_
#define _VENDINGMACHINE_H_

class Waste;
class User;


class VendingMachine {
    private:

    protected:
        float money; // For current money stored in welding machine
        int storage; // Represents the amount of materials in machine
        int storage_limit; // Represents the limit of materials that can be stored in machine
        //? pointer user olsa parraları burdan versek (inputWaste()) 
        // Account *user;
    public:
        // Constructors
        VendingMachine(); // No-args Const.
        VendingMachine(float m, float sl); // Two args Const.
        VendingMachine(VendingMachine &WM); // Copy Const.

        //Destructor
        ~VendingMachine();

        // Getters -- Setters
        float getMoney();
        void setMoney(float m);

        float getStorageInfo();
        void setStorageValue(float sv);

        float getLimit();
        void setLimit(float l);

        //Methods
        void status(); // Prints status of welding machine (eg. Current Money: X $    Storage: YY kg/amount)

        int inputWaste(Waste &W); // Function inputs wastes and check || if storage has not enough space return -1  || if there is no problems return 0 

        int withdrawMoney(User &user); // Function checks if machine has enough money to withdraw returns 0 otherwise returns -1


};

class OrganicVendingMachine : public VendingMachine{
    private:
        float storage; // Represents the amount of materials in machine
        float storage_limit; // Represents the limit of materials that can be stored in machine
    public:
        OrganicVendingMachine(); // No-args Const.
        OrganicVendingMachine(float m, float sl); // Two args Const.
        ~OrganicVendingMachine();
        int inputWaste(Waste &W);
    //TODO devamı yazılacak
};



#endif