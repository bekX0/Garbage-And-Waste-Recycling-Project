#include <iostream>
#include <string>
#include <vector>
#include "Waste.cpp"
#include "Account.cpp"
#include "VendingMachine.cpp"

using namespace std;

int logIn(vector<User> &users);
void menu(User &user, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec,  int* current_machine, int type);
int adminMenu(vector<User> &users, Admin &admin, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &MAC, int* current_machine, int* current_Omachine);
void citiesOfMachines(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &macs);
void VendingMachineMaker(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &mac, int wastetype);
//TODO login try cath 
//TODO withdraw belki belirli miktarda çekebilir
//TODO debug
int main()
{
    int currentMAC {-1}, currentOMAC{-1}, currentUser{0};

    Admin A("admin", "root");
    vector <User> users;
    
    vector<VendingMachine> MAC;
    vector<OrganicVendingMachine> OMAC;
    
    adminMenu(users, A, OMAC, MAC, &currentMAC, &currentOMAC);

    return 0;
}

int logIn(vector<User> &users)
{
    string choose, password, againPassword, username;
    int n = -3, index = -1;

    cout << "Register or Login: ";
    cin >> choose;

    if (choose == "Register")
    {   
        cout << "Enter a username: ";
        cin >> username;
        
        while(true){
            cout << "Enter a password: ";
            cin >> password;

            cout << "Enter a password again: ";
            cin >> againPassword;

            if (password == againPassword)
            {
                cout << "You have successfully registered." << endl;
                break;
            }

            else
            {
                cout << "Passwords don't match!!!" << endl;
            }
        }
        
        User user(username,password);
        user.saveInfo(user);
        users.push_back(user);


        return -1;
    }
    else if (choose == "Login")
    {
        while (true)
        {
            cout << "Enter your name: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

           if (username == "000" && password == "000")
           {
               return (-2);
               break;
           }

            // User user(username,password);
            // n = user.loginAccount(username, password);

            for(int i{0}; i< users.size() ; i++){
                    if(users[i].getName() == username && users[i].getPassword() == password){
                        index = i;
                        break;
                    }
                    if(i == users.size()-1){
                        index = -1;
                        break;
                    }
                }

            if (index >= 0)
            {
                cout << "Login successful." << endl;
                
                return index;
            }
            else if (index == -1)
            {
                cout << "Invalid password or username try again !!!" << endl;
            }
            // else if (n == -2)
            // {
            //     cout << "Invalid username try again !!!" << endl;
            // }
            // else
            // {
            //     cout << "Invalid password and username try again !!!" << endl;
            // }
        }
    }

}

void menu(User &user, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec,  int* current_machine, int type)
{
    int selection, choice, amount, counter;
    string attrib;
    float weight, money;
    Waste *Waste{nullptr};

    cout << "\n===== Welcome " << user.getName() << " =====\n" << endl;
    do
    {
    cout << "Current Balance : " << user.getWallet() << endl;
    cout << "[1] Input Waste" << endl;
    cout << "[2] Withdraw Money" << endl;
    cout << "[3] Log Out" << endl;
    cout << "Enter Choice: ";
    cin >> selection;

    switch (selection)
    {
        case 1:
        {
        
            if (type == 2)
            {
                cout << "1-Paper | 2-Plastic | 3-Glass ==> ";
                cin >> choice;

                switch (choice){
                    case 1:
                    {
                        Waste = new Paper (vec.at(*current_machine).Paper);
                        cout << "Enter amount of paper: ";
                        cin >> amount;
                        cout << "Choose the attributes of your waste: (Cardboard or Paper) ";
                        cin >> attrib;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;
                        
                        if(vec.at(*current_machine).inputWaste(*Waste) == 0){
                            (*Waste).CalculateValue();
                            money = (*Waste).GetValue();
                        
                            user.setWallet(money);
                            cout << "\nYou succesfully added waste to machine. Your balance updated!"<< endl;
                        }
                        else{
                            cout << "\nMachine has not enough place to store waste!"<< endl;
                        }
                        
                   
                        Waste=nullptr;
                        
                        break;
                    }
            
                    case 2:
                    {   
                        Waste = new Plastic(vec.at(*current_machine).Plastic);
                        cout << "Enter amount of plastic: ";
                        cin >> amount;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;
                        
                        if(vec.at(*current_machine).inputWaste(*Waste) == 0){
                            (*Waste).CalculateValue();
                            money = (*Waste).GetValue();
                        
                            user.setWallet(money);
                            cout << "\nYou succesfully added waste to machine. Your balance updated!"<< endl;
                        }
                        else{
                            cout << "\nMachine has not enough place to store waste!"<< endl;
                        }
                        
                        Waste=nullptr;

                        break;
                    }   
                
                    case 3:
                    {
                        Waste = new Glass (vec.at(*current_machine).Glass);
                        cout << "Enter amount of glass: ";
                        cin >> amount;
                        cout << "Choose the attributes of your waste: (Broken or Whole) ";
                        cin >> attrib;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;
                        
                        if(vec.at(*current_machine).inputWaste(*Waste) == 0){
                            (*Waste).CalculateValue();
                            money = (*Waste).GetValue();
                        
                            user.setWallet(money);
                            cout << "\nYou succesfully added waste to machine. Your balance updated!"<< endl;
                        }
                        else{
                            cout << "\nMachine has not enough place to store waste!"<< endl;
                        }
                        
                        Waste=nullptr;

                        break;
                    }   

                    default:
                        cout << "Invalid waste!!!" << endl;
                        break;
                }
            }
            else{
                Waste= new Organic(vc.at(*current_machine).Organic);
                cout << "Enter weight of waste: ";
                cin >> weight;
                cout << "Choose the attributes of your waste: (Fresh or Rotten) ";
                cin >> attrib;

                (*Waste).SetAttributes(attrib);
                (*Waste).SetAmount(amount);

                cout << "Completed Successfully" << endl;
                
                if(vc.at(*current_machine).inputWaste(*Waste) == 0){
                            (*Waste).CalculateValue();
                            money = (*Waste).GetValue();
                        
                            user.setWallet(money);
                            
                            cout << "\nYou succesfully added waste to machine. Your balance updated!";
                        }
                        else{
                            cout << "\nMachine has not enough place to store waste!";
                        }
                
                Waste=nullptr;

            }
            break;
        }    
    
        case 2:
        {
            if (type == 1)
            {
                vc.at(*current_machine).withdrawMoney(user);
                cout << "Don't forget your money!!" << endl;
            }
            else
            {
                vec.at(*current_machine).withdrawMoney(user);
                cout << "Don't forget your money!!" << endl;
            }
            break;
        }

        case 3:
            cout << "===== Goodbye " << user.getName() << " =====\n" << endl;
            user.saveInfo(user);
            return;
    
    }
    }while (true);

}


//TODO Log out func


int adminMenu(vector<User> &users, Admin &admin, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &MAC, int* current_machine, int* current_Omachine)
{
    
    int selection,accepted, logged;
    int type, temp;
    char choose;
    float money;
    string cityname, name, pass;
    do{
        cout << "Waiting for admin log in." << endl;
        cout << "Username: ";
        cin >> name;
        cout << "Password: ";
        cin >> pass;
        if(admin.loginAdmin(name,pass) == 1){

            //!makine burdan tekrar user menu kısmına dönmüyor çünkü admin menü açmanın bilgisi sızdırılmış (admine mesaj gidiyormuş gibi düşebiliriz)
        }
        else{
            continue;
        }


        cout << "\n===== Welcome " << admin.getName() << " =====\n" << endl;
        do{
        cout << "[1] Get Info" << endl;
        cout << "[2] Create a Vending Machine" << endl;
        cout << "[3] Check Current Balance" << endl;
        cout << "[4] Set This Vending Machine" << endl;
        cout << "[5] Publish Machine" << endl;
        cout << "[6] Turn Off" << endl;//!kapatmıyo
        cout << "Enter Choice : ";
        cin >> selection;
    
        switch (selection)
        {
        case 1:
            admin.getInfo();
            break;
    
        case 2:
            cout << "Welcome to Vengding Machine Setter!" << endl;
            cout << "Accepted waste type: " << endl
                 << "1-Organic | 2-Anorganic ==> ";
            cin >> accepted;
    
            try
            {
                if (accepted != 1 && accepted != 2)
                    throw 0;
    
                VendingMachineMaker(vc, MAC ,accepted);
            }
            catch (int &ecp)
            {
                cerr << "Just 1 or 2!" << endl;
            }
    
            break;
    
        case 3:
            cout << "[1] View Current Balance" << endl;
            cout << "[2] Deposit Money" << endl;
    
            cout << "Enter Choice : ";
            cin >> selection;

            if (type == 1)
            {
               if (selection == 1)
              {
                 cout << "Vending Machine Balance: " << vc.at(*current_machine).getMoney() << endl;
              }
               else if (selection == 2)
               {
                 cout << "How Much Change to Vending Machine Balance: ";
                 cin >> money;
    
                 vc.at(*current_machine).setMoney(money);
    
                 cout << "New Vending Machine Balance: " << vc.at(*current_machine).getMoney() << endl;
               }
            }
            else
            {
               if (selection == 1)
              {
                 cout << "Vending Machine Balance: " << MAC.at(*current_machine).getMoney() << endl;
              }
               else if (selection == 2)
               {
                 cout << "How Much Change to Vending Machine Balance: ";
                 cin >> money;
    
                 MAC.at(*current_machine).setMoney(money);
    
                 cout << "New Vending Machine Balance: " << MAC.at(*current_machine).getMoney() << endl;
               }
            }


    
            break;
        
    
        case 4:
            citiesOfMachines(vc, MAC);

            cout << endl << "Select number of city: ";
            cin >> temp;

            if (temp > MAC.size())
            {
                *current_machine = -1;
                type = 1;
                *current_Omachine = temp;
                *current_Omachine = *current_Omachine - MAC.size()-1;
            }

            else
            {
                *current_Omachine = -1;
                type = 2;
                *current_machine = temp;
                *current_machine = *current_machine -1;
            }

            break;
    
        case 5:
            while(true){
                logged = logIn(users);
                if(logged == -2){
                    break;
                }

                else if (logged == -1)
                {
                    continue;
                }

                else{
                    if (type == 2)
                    menu((users.at(logged)), vc, MAC, current_machine, type);

                    else
                    menu((users.at(logged)), vc, MAC, current_Omachine, type);
                }
            }
            break;
        case 6:
            return 0;
            break;
        }
        }while (true);
        
    }while(true);
        
}

void VendingMachineMaker(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &mac, int wastetype)
{
    float price1, price2, price3, price4;
    float storage, money;
    string cityname,a;
    
    if(wastetype == 1)
    {
        cout << "City Name: ";
        cin >> cityname;

        cout << "Deposit Money: ";
        cin >> money;

        cout << "Input the storage limit: ";
        cin >> storage;

        OrganicVendingMachine New(money, storage, cityname);
        vc.push_back(New);

        cout << "Set the price of Organic waste: ";
        cin >> price1;

        
        vc.at(vc.size()-1).Organic.SetPrice(price1);

        
    }
    else if(wastetype == 2)
    {
        cout << "City Name: ";
        cin >> cityname;

        cout << "Deposit Money: ";
        cin >> money;

        cout << "Input the storage limit: ";
        cin >> storage;

        VendingMachine New(money, storage, cityname);
        mac.push_back(New);

        cout << "Set the price for Paper: ";
        cin >> price2;
        cout << "Set the price for Plastic: ";
        cin >> price3;
        cout << "Set the price for Glass: ";
        cin >> price4;

        mac.at(mac.size()-1).Paper.SetPrice(price2);
        mac.at(mac.size()-1).Plastic.SetPrice(price3);
        mac.at(mac.size()-1).Glass.SetPrice(price4);   
    }
}

void citiesOfMachines(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &macs){
    int i{0};
    cout << "Anorganic Machines:" << endl;

    for(; i< macs.size() ; i++){
        cout << "[" <<  i+1 << "] " << macs.at(i).getCity() << endl;
    }

    cout << "Organic Machines:" << endl;

    for(; i< vc.size()+macs.size() ; i++){
        cout << "[" <<  i+1 << "] " << vc.at(i-macs.size()).getCity() << endl;
    }
}
