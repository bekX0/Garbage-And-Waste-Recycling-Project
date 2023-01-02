#include <iostream>
#include <string>
#include <vector>
#include "Waste.cpp"
#include "Account.cpp"
#include "VendingMachine.cpp"

using namespace std;

void logIn(vector<VendingMachine> &vec, vector<Paper> &pap, vector<Glass> &glas, vector<Plastic> &plas, vector<Organic> &org);
void menu(User &user);
void adminMenu(Admin &admin);

int main()
{
    Account *p = new Admin();
    Admin *admin = new Admin;

    vector<VendingMachine> MAC;
    vector<OrganicVendingMachine> OMAC;
    vector<Paper> paper;
    vector<Glass> glass;
    vector<Plastic> plastic;
    vector<Organic> organic;

    cout << "System Setting Up" << endl;
    cout << "Waiting for admin..." << endl;

    // do{
    //   logIn(MAC);
    //}while(true); // makine hicbir zaman kapanmayacak

    return 0;
}

void logIn(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec, vector<Paper> &pap, vector<Glass> &glas, vector<Plastic> &plas, vector<Organic> &org)
{
    string choose, password, againPassword, username;
    User obj;
    int n = -2;

    cout << "Register or Login";
    cin >> choose;

    if (choose == "Register")
    {
        cout << "Enter a username: ";
        cin >> username;

        cout << "Enter a password";
        cin >> password;

        cout << "Enter a password again: ";
        cin >> againPassword;

        if (password == againPassword)
        {
            cout << "You have successfully registered." << endl;
        }

        else
        {
            cout << "Passwords don't match!!!" << endl;
        }
    }
    else if (choose == "Login")
    {

        while (n != 1)
        {
            cout << "Enter your name: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            n = obj.loginAccount(username, password);

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

    menu(obj);
}

void menu(User &user, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &vec, vector<Paper> &pap, vector<Glass> &glas, vector<Plastic> &plas, vector<Organic> &org)
{
    int selection, choice, amount, counter, machine;
    string attrib;
    float weight;

    cout << "===== Welcome" << user.getName() << "=====" << endl;
    cout << "Current Balance : " << user.getWallet() << endl;
    cout << "[1] See all Machines" << endl;
    cout << "[2] Withdraw Money" << endl;
    cout << "[3] Log Out" << endl;
    cout << "Enter Choice : ";
    cin >> selection;

    switch (selection)
    {
    case 1:
    {
    
        citiesOfMachines(vc, vec);

        cout << endl << "Choose one: ";
        cin >> machine;

        if (machine )
        {
            cout << "1-Paper | 2-Plastic | 3-Glass ==> ";
            cin >> choice;

        switch (choice)
        {
            case 1:
            {
                Paper waste;
                cout << "Enter amount of paper: ";
                cin >> amount;
                cout << "Choose the attributes of your waste: (Cardboard or Paper) ";
                cin >> attrib;

                waste.SetAttributes(attrib);
                waste.SetAmount(amount);

                cout << "Completed Successfully" << endl;
                break;
            }
            
            case 2:
            {
                Plastic waste;
                cout << "Enter amount of plastic: ";
                cin >> amount;

                waste.SetAmount(amount);

                cout << "Completed Successfully" << endl;
                break;
            }
        

            case 3:
            {
                Glass waste;
                cout << "Enter amount of glass: ";
                cin >> amount;
                cout << "Choose the attributes of your waste: (Broken or Whole) ";
                cin >> attrib;

                waste.SetAttributes(attrib);
                waste.SetAmount(amount);

                cout << "Completed Successfully" << endl;
                break;
            }

            default:
            {
                cout << "Invalid waste!!!" << endl;
                break;
            }
        }
        }

        else
        {
            Organic waste;
            cout << "Enter weight of waste: ";
            cin >> weight;
            cout << "Choose the attributes of your waste: (Fresh or Rotten) ";
            cin >> attrib;

            waste.SetAttributes(attrib);
            waste.SetWeight(weight);

            cout << "Completed Successfully" << endl;
        }
    }
    case 2:
        int status
        break;

    }
}

//cout << "===== Goodbye" << user.getName() << "=====" << endl;
//user.saveInfo(user);
//TODO Log out func

 
//} cd "d:\Codes\C++\Garbage-And-Waste-Recycling-Project\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

void adminMenu(Admin &admin, vector<OrganicVendingMachine> &vc, vector<VendingMachine> &MAC, vector<Paper> &pap, vector<Glass> &glas, vector<Plastic> &plas, vector<Organic> &org)
{
    int selection, money, accepted;
    char choose;
    double money;
    string cityname;

    cout << "===== Welcome" << admin.getName() << "=====" << endl;
    cout << "[1] Get Info" << endl;
    cout << "[2] Set a Vending Machine" << endl;
    cout << "[3] Check Current Balance" << endl;
    cout << "[4] Log Out" << endl;
    cout << "[5] Turn Off" << endl;
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

            VendingMachineMaker(MAC, accepted);
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
        if (selection == 1)
        {
            cout << "Vending Machine Balance: " << MAC.getMoney() << endl;
        }
        else if (selection == 2)
        {
            cout << "How Much Change to Vending Machine Balance: ";
            cin >> money;

            MAC.setMoney(money);

            cout << "New Vending Machine Balance: " << MAC.getMoney() << endl;
        }

        break;

        // case 5:
    }
}

void VendingMachineMaker(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &mac, vector<Paper> &pap, vector<Glass> &glas, vector<Plastic> &plas, vector<Organic> &org, int wastetype)
{
    int price1, price2, price3, price4;
    int storage, money;
    string cityname,a;

    try
    {
        if (wastetype == 1)
            throw 1;
        if (wastetype == 2)
            throw a;
    }
    catch (int &x)
    {
        cout << "City Name: ";
        cin >> cityname;

        cout << "Deposit Money: ";
        cin >> money;

        cout << "Input the storage limit: ";
        cin >> storage;

        VendingMachine New(money, storage, cityname);
        mac.push_back(New);

        cout << "Set the price of Organic waste: ";
        cin >> price1;

        Organic New1;
        New1.SetPrice(price1);

        org.push_back(New1);
    }
    catch (char &x)
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

        Paper New2;
        Plastic New3;
        Glass New4;

        New2.SetPrice(price2);
        New3.SetPrice(price3);
        New4.SetPrice(price4);

        pap.push_back(New2);
        plas.push_back(New3);
        glas.push_back(New4);
    }
}

void citiesOfMachines(vector<OrganicVendingMachine> &vc, vector<VendingMachine> &macs){

    cout << "Anorganic Machines:" << endl;

    for(int i{0} ; i< macs.size() ; i++){
        cout << "[" <<  i+1 << "] " << macs.at(i).getCity() << endl;
    }

    cout << "Organic Machines:" << endl;

    for( i  ; i< vc.size() ; i++){
        cout << "[" <<  i+1 << "] " << vc.at(i).getCity() << endl;
    }
}