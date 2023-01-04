#include <iostream>
#include <string>
#include <vector>
#include "Waste.cpp"
#include "Account.cpp"
#include "VendingMachine.cpp"

using namespace std;

int logIn(vector<User> &users);
void menu(User &user, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec,  int* current_machine, int type);
void adminMenu(Admin &&admin, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &MAC, int* current_machine);
void citiesOfMachines(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &macs);
void VendingMachineMaker(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &mac, int wastetype);
//TODO user menü değişcek artık makine nerde biliyor
//TODO withdraw belki belirli miktarda çekebilir
//TODO debug
int main()
{
    int type;
    string city;
    int currentMAC {0};

    Admin A;
    vector <User> users;
    
    vector<VendingMachine> MAC;
    vector<OrganicVendingMachine> OMAC;
    

    cout << "Welcome to Vengding Machine Setter!" << endl;
    //cout << "To create new machine type 1 . If you done creating machines type 0"; //do while
    cout << "Select Vending Machine Type: " << endl << "1-Organic | 2-Anorganic ==> ";
    cin >> type;

    VendingMachineMaker(OMAC, MAC, type);
    logIn(users);


    
    //?menu(*p, OMAC, MAC, paper, glass, plastic, organic, current_machine);
    //adminMenu (*admin, OMAC, MAC, paper, glass, plastic, organic, &current_machine);
    // do{
    //   logIn(MAC);
    //}while(true); // makine hicbir zaman kapanmayacak

    return 0;
}

int logIn(vector<User> &users)
{
    string choose, password, againPassword, username;
    int n = -2, a;

    cout << "Register or Login";
    cin >> choose;

    if (choose == "Register")
    {   
        cout << "Enter a username: ";
        cin >> username;
        
        while(true){
            cout << "Enter a password";
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
        users.push_back(User(username,password));
    }
    else if (choose == "Login")
    {
        while (n != 1)
        {
            cout << "Enter your name: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            for(int i{0}; i< 10 ; i++){
                if(users[i].getName() == username){
                    if(users[i].getPassword() == password){
                        a = i;
                    }
                }
                else{
                    continue;
                }
            }

            n = users[a].loginAccount(username, password);

            if (n == 1)
            {
                cout << "Login successful." << endl;
            }
            else if (n == -1)
            {
                cout << "Invalid password try again !!!" << endl;
            }
            else if (n == -2)
            {
                cout << "Invalid username try again !!!" << endl;
            }
            else
            {
                cout << "Invalid password and username try again !!!" << endl;
            }
        }
    }
}

void menu(User &user, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec,  int* current_machine, int type)
{
    int selection, choice, amount, counter;
    string attrib;
    float weight;
    Waste *Waste{nullptr};

    cout << "===== Welcome" << user.getName() << "=====" << endl;
    cout << "Current Balance : " << user.getWallet() << endl;
    cout << "[1] Input Waste" << endl;
    cout << "[2] Withdraw Money" << endl;
    cout << "[3] Log Out" << endl;
    cout << "Enter Choice : ";
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
                        Waste = new Paper ();
                        cout << "Enter amount of paper: ";
                        cin >> amount;
                        cout << "Choose the attributes of your waste: (Cardboard or Paper) ";
                        cin >> attrib;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;
                        
                        Waste=nullptr;

                        break;
                    }
            
                    case 2:
                    {   
                        Waste = new Plastic();
                        cout << "Enter amount of plastic: ";
                        cin >> amount;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;

                        Waste=nullptr;

                        break;
                    }   
                
                    case 3:
                    {
                        Waste = new Glass ();
                        cout << "Enter amount of glass: ";
                        cin >> amount;
                        cout << "Choose the attributes of your waste: (Broken or Whole) ";
                        cin >> attrib;

                        (*Waste).SetAttributes(attrib);
                        (*Waste).SetAmount(amount);

                        cout << "Completed Successfully" << endl;

                        Waste=nullptr;

                        break;
                    }   

                    default:
                        cout << "Invalid waste!!!" << endl;
                        break;
                }
            }
            else{
                Waste= new Organic();
                cout << "Enter weight of waste: ";
                cin >> weight;
                cout << "Choose the attributes of your waste: (Fresh or Rotten) ";
                cin >> attrib;

                (*Waste).SetAttributes(attrib);
                (*Waste).SetAmount(amount);

                cout << "Completed Successfully" << endl;

                Waste=nullptr;

            }
        }    
    
        case 2:
        {
            int status;
            break;
        }

        case 3:
            cout << "===== Goodbye" << user.getName() << "=====" << endl;
            user.saveInfo(user);

            break;
    
    }
}


//TODO Log out func

 
//} cd "d:\Codes\C++\Garbage-And-Waste-Recycling-Project\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

void adminMenu(Admin &admin, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &MAC, int* current_machine)
{
    
    int selection,accepted;
    char choose;
    float money;
    string cityname;

    cout << "===== Welcome" << admin.getName() << "=====" << endl;
    cout << "[1] Get Info" << endl;
    cout << "[2] Create a Vending Machine" << endl;
    cout << "[3] Check Current Balance" << endl;
    cout << "[4] Set This Vending Machine" << endl;
    cout << "[5] Log Out" << endl;//! çıkış yapmıyo
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

    case 3://!sadece düz vending machine parasını kontrol ediyo
        cout << "[1] View Current Balance" << endl;
        cout << "[2] Deposit Money" << endl;

        cout << "Enter Choice : ";
        cin >> selection;
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

        break;
    

    case 4:
        citiesOfMachines(vc, MAC);
        cin >> *current_machine;
        break;

    case 5:
        cout << "===== Goodbye" << admin.getName() << "=====" << endl;
        break;
    }
}

void VendingMachineMaker(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &mac, int wastetype)
{
    int price1, price2, price3, price4;
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

    cout << "Anorganic Machines:" << endl;

    for(int i{0} ; i< macs.size() ; i++){
        cout << "[" <<  i+1 << "] " << macs.at(i).getCity() << endl;
    }

    cout << "Organic Machines:" << endl;

    for( int i{0}  ; i< vc.size() ; i++){
        cout << "[" <<  i+1 << "] " << vc.at(i).getCity() << endl;
    }
}

int UserControl(User *arr, string username, string pass){
    for(int i{0}; i< 10 ; i++){
        if(arr[i].getName() == username){
            if(arr[i].getPassword() == pass){
                return i;
            }
        }
        else{
            continue;
        }
    }

}