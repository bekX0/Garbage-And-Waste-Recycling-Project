#ifndef _WELDINGMACHINE_H_
#define _WELDINGMACHINE_H_
#include <Account.h>
#include <Waste.h>

class WeldingMachine{
    private:

    protected:
        float money; // For current money stored in welding machine
        float storage; // Represents the amount of materials in machine
        float storage_limit; // Represents the limit of materials that can be stored in machine
        //? pointer user olsa parraları burdan versek (inputWaste()) 
    public:
        // Constructors
        WeldingMachine(); // No-args Const.
        WeldingMachine(float money, float storage_limit); // Two args Const.
        WeldingMachine(WeldingMachine &WM); // Copy Const.

        // Getters -- Setters
        float getMoney();
        void setMoney();

        float getStorageInfo();
        void setStorageValue();

        float getLimit();
        void setLimit();

        //Methods
        void status(); // Prints status of welding machine (eg. Current Money: X $    Storage: YY kg/amount)

        int inputWaste(Waste &W); // Function inputs wastes and check || if storage has not enough space return -1 || if machine has not enough money to give return -2 || if there is no problems return 0 


};



#endif