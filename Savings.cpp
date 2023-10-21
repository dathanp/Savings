//
//  Savings.cpp
//  AirgeadBank
//
//  Created by Dathan Pompa on 10/6/23.
//
#include <iomanip>
#include <iostream>
#include "Savings.h"

using namespace std;

// Constructor
Savings::Savings(double investment, double monthDep, int years, double rate)
{
    // Stores object data into private
    this->initialInvestment = investment;
    this->monthlyDeposit = monthDep;
    this->numOfYears = years;
    this->interestRate = rate;
}
//Destructor
Savings::~Savings(){}

//Print details
void Savings::withMonthlyDeposit() {
    cout << " Balance and Interest with additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    formatTable();
    //Iterate for given years and calc interest earned
    int currYear = 1;
    double yearEndBalance = this->initialInvestment;
    while (currYear <= this->numOfYears) {
        //Calc interest monthly and find compoud interest
        int month = 1;
        double interestEarned = 0.0;
        double monthEndBalance = yearEndBalance;
        while (month <= 12) {
            //Add monthly deposit
            monthEndBalance += this->monthlyDeposit;
            //Calc monthly interest, interest rate is for annual. so divide the rate by 12
            double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
            //Add the monthly interest to yearly interest earned
            interestEarned += monthlyInterest;
            // add the interest to monthEnd balance
            monthEndBalance += monthlyInterest;
            //Increase the month by 1
            month++;
        }
        // After 12 months
            yearEndBalance = monthEndBalance;
        //Print the results for each year
        cout << right << setw(10) << currYear << fixed << setprecision(2)<< setw(20) << yearEndBalance    << setw(35) << interestEarned << endl;
        currYear++;
    }
}

void Savings::noMonthlyDeposit() {
    cout << " Balance and Interest without additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    //Runs format table method
    formatTable();
    int currYear = 1;
    double yearEndBalance = this->initialInvestment;
    while (currYear <= this->numOfYears) 
    {
        //Calc interest
        double interestEarned = yearEndBalance * this->interestRate / 100;
        //Add it to yearEnd Balance
        yearEndBalance += interestEarned;
        //Print the results for each year
        cout << right << setw(10) << currYear << fixed << setprecision(2)<< setw(20) << yearEndBalance    << setw(35) << interestEarned << endl;
        //Increase the year by one
        currYear++;
    }
}

void Savings::formatTable()
{
    //Print table heading
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}
