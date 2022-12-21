#include <iostream>
#include "Waste.h"
#include "Account.h"
#include "VendingMachine.h"

using namespace std;

int main ()
{   
    string choose,password,username;
    int n=-2, 

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
            cin >> name; 

            cout << "Enter your password: ";
            cin >> password;

            n=obje.login(name,password);  //! Obje yazilacak!!!

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

    menu(user_obje);

}

void menu(User &user){
    int selection;
    cout << "===== Welcome" << user.get_name() << "=====" << endl;
    cout << "Current Balance : " << user.get_wallet() << endl << endl;
    cout << "[1] " << "Withdraw Money" << endl;
    cout << "[2] " << "Deposit Waste" << endl;
    cout << "[3] " << "Log Out" << endl;
    cout << "Enter Choice : ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        //TODO withdraw money fonsksiyonu user için-
        break;
    
    default:
        break;
    }
}
