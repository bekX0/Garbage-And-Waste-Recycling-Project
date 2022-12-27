#include <iostream>
#include <string>
#include <vector>
#include "Waste.cpp"
#include "Account.cpp"
#include "VendingMachine.cpp"

using namespace std;

void logIn();
void menu(User &user);
void adminMenu(Admin &admin);

<<<<<<< Updated upstream
int main (){
    Account *p = new Admin();
    Admin *admin = new Admin; 
    
    //vector <VendingMachine> MAC;

    cout << "System Setting Up" << endl;
    cout << "Waiting for admin..." << endl;
    
    
    
    
  
    //do{
      //  logIn(MAC);
    //}while(true); // makine hicbir zaman kapanmayacak
    
    return 0;
}

void logIn(vector <VendingMachine>& vec){
    string choose,password,againPassword,username;
=======
int main()
{
    Account *p = new Admin();
    Admin *admin = new Admin;

    // vector <VendingMachine> MAC;

    cout << "System Setting Up" << endl;
    cout << "Waiting for admin..." << endl;

    // do{
    //     logIn(MAC);
    // }while(true); // makine hicbir zaman kapanmayacak

    return 0;
}

void logIn(vector<VendingMachine> &vec)
{
    string choose, password, againPassword, username;
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
            n=obj.loginAccount(username,password);  
=======
            n = obj.loginAccount(username, password);
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
void menu(User &user, vector <VendingMachine>& vect){
=======
void menu(User &user, vector<VendingMachine> &vect)
{
>>>>>>> Stashed changes
    int selection, choice, amount;
    string attrib;
    float weight;

<<<<<<< Updated upstream
    cout << "===== Welcome" << user.getName() << "=====" << endl; 
    cout << "Current Balance : " << user.getWallet() << endl << endl; 
    cout << "[1] " << "City name: " << endl;
    cout << "[3] " << "Log Out" << endl;
=======
    cout << "===== Welcome" << user.getName() << "=====" << endl;
    cout << "Current Balance : " << user.getWallet() << endl
         << endl;
    cout << "[1] "
         << "City name: " << endl;
    cout << "[3] "
         << "Log Out" << endl;
>>>>>>> Stashed changes
    cout << "Enter Choice : ";
    cin >> selection;

    switch (selection)
    {
    case 1:
<<<<<<< Updated upstream
            if ()
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
                }
                break;
            case 2:
                {
                Plastic waste;
                cout << "Enter amount of plastic: ";
                cin >> amount;
                
                waste.SetAmount(amount);
                
                cout << "Completed Successfully" << endl;
                }
                break;

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
                }
                break;

            default:
                cout << "Invalid waste!!!" << endl;
                break;
            }
=======

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
        }
        break;
        case 2:
        {
            Plastic waste;
            cout << "Enter amount of plastic: ";
            cin >> amount;

            waste.SetAmount(amount);

            cout << "Completed Successfully" << endl;
        }
        break;

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
>>>>>>> Stashed changes
        }
        break;

        default:
            cout << "Invalid waste!!!" << endl;
            break;
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

        break;

    case 3:
        // cout << "===== Goodbye" << user.getName() << "=====" << endl;
        // user.saveInfo(user);
        // TODO Log out func

    default:
        break;
    }
 }
//}  cd "d:\Codes\C++\Garbage-And-Waste-Recycling-Project\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

<<<<<<< Updated upstream
void adminMenu(Admin &admin, VendingMachine &MAC){
    int selection,money,accepted;
=======
void adminMenu(Admin &admin, VendingMachine &MAC)
{
    int selection, money, accepted;
>>>>>>> Stashed changes
    char choose;
    double money;
    string cityname;

<<<<<<< Updated upstream
    cout << "===== Welcome" << admin.getName() << "=====" << endl; 
    cout << "[1] " << "Get Info" << endl;
    cout << "[2] " << "Set Vending Machine" << endl; 
    cout << "[3] " << "Check Current Balance" << endl;
    cout << "[4] " << "Log Out" << endl;
    cout << "[5] " << "Turn Off" << endl;
=======
    cout << "===== Welcome" << admin.getName() << "=====" << endl;
    cout << "[1] "
         << "Get Info" << endl;
    cout << "[2] "
         << "Set Vending Machine" << endl;
    cout << "[3] "
         << "Check Current Balance" << endl;
    cout << "[4] "
         << "Log Out" << endl;
    cout << "[5] "
         << "Turn Off" << endl;
>>>>>>> Stashed changes
    cout << "Enter Choice : ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        admin.getInfo();
        break;

<<<<<<< Updated upstream
        case 2:
                cout << "Welcome to Vengding Machine Setter!" << endl;
                cout << "Accepted waste type: " << endl << "1-Organic | 2-Anorganic ==> ";
                cin >> accepted;

                try
                {
                    if (accepted != 1 && accepted !=2) throw 1;
                    
                    cout << "City Name: ";
                    cin >> cityname;
                        
                    cout << "Deposit Money: ";
                    cin >> money;

                    if (accepted == 1)
                    {
                        cout << "Set the price of Organic waste: ";
                        cin >> 
                    }

                    else
                    {

                    }

                    MAC.setMoney(money);
                    cout << "New Vending Machine Balance: " << MAC.getMoney() << endl;

                }
                catch (int &x)
                {
                    cout << "Just 1 or 2!";
                }


            break;
            
        case 3:
            cout << "[1] " << "View Current Balance" << endl;
            cout << "[2] " << "Deposit Money" << endl; 
        
            cout << "Enter Choice : ";
            cin >> selection;
            if(selection == 1){
                cout << "Vending Machine Balance: " << MAC.getMoney() << endl;
            }
            else if(selection == 2){
                cout << "How Much Change to Vending Machine Balance: ";
                cin >> money;
                
                MAC.setMoney(money);

                cout << "New Vending Machine Balance: " << MAC.getMoney() << endl;
            }
            
            break;
=======
    case 2:
        cout << "Welcome to Vengding Machine Setter!" << endl;
        cout << "Accepted waste type: " << endl
             << "1-Organic | 2-Anorganic ==> ";
        cin >> accepted;
>>>>>>> Stashed changes

        try
        {
            if (accepted != 1 && accepted != 2)
                throw 1;

            cout << "City Name: ";
            cin >> cityname;

            cout << "Deposit Money: ";
            cin >> money;

            if (accepted == 1)
            {
                cout << "Set the price of Organic waste: ";
                cin >>
            }

            else
            {
            }

            MAC.setMoney(money);
            cout << "New Vending Machine Balance: " << MAC.getMoney() << endl;
        }
        catch (int &x)
        {
            cout << "Just 1 or 2!";
        }

        break;

    case 3:
        cout << "[1] "
             << "View Current Balance" << endl;
        cout << "[2] "
             << "Deposit Money" << endl;

<<<<<<< Updated upstream
        case 5:
            
=======
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

    case 4:
        cout << "===== Goodbye" << admin.getName() << "=====" << endl;
        break;

    case 5:
>>>>>>> Stashed changes
    }
}