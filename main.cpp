//
//  main.cpp
//  AirgeadBank
//
//  Created by Dathan Pompa on 10/6/23.
//
#include <iostream>
#include "Savings.h"
using namespace std;

int main() {
    
    while (1) {
        // Creates place holder data types
        double investment, monthlyDeposit, interestRate;
        int years;
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        cout << endl;
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        // Gather user data
        cin >> investment;
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        cout << "Annual Interest: %";
        cin >> interestRate;
        cout << "Number of years";
        cin >> years;
        cout << endl;
        //checks to see if input is valid to prevent breaking the program
        try {
            //validates if each input is a non negative number.
            if(investment >= 0 && monthlyDeposit >= 0 && interestRate >= 0 && years >= 0){
                continue;
            }
            else
            {
                throw 404;
            }
            //error message
        } catch (int myAns) {
            cout << "Please enter only positive numbers" << endl;
            cout << "Error: " << myAns;
        
        }
        
        //With given data, store it in the object
        Savings userSavings = Savings(investment, monthlyDeposit, years, interestRate);
        cout << endl;
        // run the no monthly deposit function
        userSavings.noMonthlyDeposit();
        cout << endl;
        if(monthlyDeposit > 0)
        {
            // if not empty run with monthly deposit method
            userSavings.withMonthlyDeposit();
        }
        // try catch block for getting user to continue loop or break loop
        try {
            // create choice string for user
            string choice;
            cout << endl << "Do you want to try again with different amounts? Y / N" << endl;
            cin >> choice;
            if(choice == "n" || choice == "N")
            {
                // ends loop
                break;
            }
            else if (choice == "y" || choice == "Y")
            {
                continue;
            }
            else
            {
                throw(choice);
            }
        // throws error message
        } catch (string myChoice) {
            cout << "Please enter only Y/y or N/n to continue";
            cout << "Your answer was" << myChoice;
        }
        cout << endl;
    }
    return 0;
}
