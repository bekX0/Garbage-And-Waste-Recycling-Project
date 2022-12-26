#include <iostream>
#include <string>
#include <stdio.h>
#include "Waste.cpp"
#include "Account.cpp"
#include "VendingMachine.cpp"

using namespace std;

void logIn();
void menu(User &user);
void adminMenu(Admin &admin);

int main (){   
    do{
        logIn();
    }while(true); // makine hiçbir zaman kapanmayacak
    
    return 0;
}

void logIn(){
    string choose,password,againPassword,username;
    User obj;
    int n=-2;

    cout << "Register or Login" ;
    cin >> choose;
    
    if(choose == "Register"){
        cout << "Enter a username: ";
        cin >> username;

        cout << "Enter a password";
        cin >> password;

        cout << "Enter a password again: ";
        cin >> againPassword;
        
        if(password == againPassword){
            cout << "You have successfully registered." << endl;
        }

        else {
            cout << "Passwords don't match!!!" << endl; 
        }
    }   
    else if(choose == "Login"){
        
        while(n != 1){
            cout << "Enter your name: ";
            cin >> username; 

            cout << "Enter your password: ";
            cin >> password;

            n=obj.loginAccount(username,password);  //! account sınıfında login yok ya giren kişi adminse

            if(n == 1){
                cout << "Login successful." << endl;
            }
            else if(n == -1){
                cout << "Invalid password try again !!!" << endl;
            }
            else if (n== -2){
                cout << "Invalid username try again !!!" << endl;
            }
            else{
                cout << "Invalid password and username try again !!!" << endl;
            }
        }
    }

    menu(obj);

}

void menu(User &user){
    VendingMachine MAC;
    int selection, choice, amount;
    string attrib;
    float weight;

    cout << "===== Welcome" << user.getName() << "=====" << endl; 
    cout << "Current Balance : " << user.getWallet() << endl << endl; 
    cout << "[1] " << "Withdraw Money" << endl;
    cout << "[2] " << "Deposit Waste" << endl;
    cout << "[3] " << "Log Out" << endl;
    cout << "Enter Choice : ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        if(MAC.withdrawMoney(user) == 0){
            cout << "Succesfull!" << endl;
            cout << "Don't forget your cash!!" << endl;
        }
        else{
            cout << "Operation failed!" << endl;
            cout << "Machine have not enough money to withdraw!" << endl;
        }
        break;
    
    case 2:
        cout << "1-Organic | 2-Anorganic" << endl;
        cin >> choice;
        
        if(choice == '2'){
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
        }
        else{
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
    cout << "===== Goodbye" << user.getName() << "=====" << endl; 
    user.saveInfo(user);
    //TODO Log out func
    
    default:
        break;
    }
}//cd "d:\Codes\C++\Garbage-And-Waste-Recycling-Project\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

void adminMenu(Admin &admin, VendingMachine &MAC){
    int selection;

    cout << "===== Welcome" << admin.getName() << "=====" << endl; 
    cout << "[1] " << "Get Info" << endl;
    cout << "[2] " << "Set Price" << endl; 
    cout << "[3] " << "Check Current Balance" << endl; 
    cout << "[4] " << "Log Out" << endl;
    cout << "[5] " << "Turn Off" << endl;
    cout << "Enter Choice : ";
    cin >> selection;

    switch(selection){
        case 1:
            admin.getInfo();
            break;

        case 2:
            
            
        case 3:
            MAC.getMoney();
            break;

        case 4:
            cout << "===== Goodbye" << admin.getName() << "=====" << endl; 
            break;

        case 5:
    }
}
